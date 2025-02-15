//===----------------------------------------------------------------------===//
//
// Copyright (C) 2022 Sophgo Technologies Inc.  All rights reserved.
//
// TPU-MLIR is licensed under the 2-Clause BSD License except for the
// third-party components.
//
//===----------------------------------------------------------------------===//

#include "../Lowering.h"

using namespace tpu_mlir;
using namespace tpu_mlir::helper;
using namespace mlir;

Value top::MulOp::lowering_int8_bm1684x(bool asymmetric) {
  auto op = getOperation();
  const int nInputs = op->getNumOperands();
  if (asymmetric == false) {
    OpBuilder builder(op);
    std::vector<Value> operands;
    double scale;
    int64_t zp_o;
    double scale_o;
    Quant::getScaleAndZeroPoint(output(), scale_o, zp_o, asymmetric);

    double scale_i;
    int64_t zp;
    for (int i = 0; i < nInputs; i++) {
      auto input = op->getOperand(i);
      operands.push_back(input);
      Quant::getScaleAndZeroPoint(input, scale_i, zp, asymmetric);
      if (i == 0)
        scale = scale_i;
      else
        scale *= scale_i;
    }

    scale /= scale_o;

    int multiplier;
    int rshift;
    get_scale_and_shift(scale, multiplier, rshift, 8);

    builder.setInsertionPointAfter(op);
    std::vector<NamedAttribute> attrs;
    attrs.push_back(builder.getNamedAttr("do_relu", do_reluAttr()));
    attrs.push_back(builder.getNamedAttr(
        "multiplier", builder.getI64IntegerAttr(multiplier)));
    attrs.push_back(
        builder.getNamedAttr("rshift", builder.getI64IntegerAttr(rshift)));
    auto newType = Quant::getQuantInt8Type(output(), asymmetric);
    auto newOp =
        builder.create<tpu::MulOp>(op->getLoc(), newType, operands, attrs);
    return newOp.output();
  } else {
    return lowering_f32_bm1684x();
  }
}

Value top::MulOp::lowering_f32_bm1684x() {
  return lowering_common_float<tpu::MulOp, Float32Type>(getOperation());
}

Value top::MulOp::lowering_bf16_bm1684x() {
  return lowering_common_float<tpu::MulOp, BFloat16Type>(getOperation());
}

Value top::MulOp::lowering_f16_bm1684x() {
  return lowering_common_float<tpu::MulOp, Float16Type>(getOperation());
}

Value top::MulOp::lowering_quant_bm1684x() {
  Builder builder(getContext());
  auto in0_f32 = do_cast(inputs()[0], builder.getF32Type(), false);
  auto in1_f32 = do_cast(inputs()[1], builder.getF32Type(), false);
  auto op = getOperation();
  op->setOperand(0, in0_f32);
  op->setOperand(1, in1_f32);
  auto type = output().getType();
  auto v = lowering_common_float<tpu::MulOp>(op);
  return do_cast(v, type, true);
}
