//===----------------------------------------------------------------------===//
//
// Copyright (C) 2022 Sophgo Technologies Inc.  All rights reserved.
//
// TPU-MLIR is licensed under the 2-Clause BSD License except for the
// third-party components.
//
//===----------------------------------------------------------------------===//

#include "../Lowering.h"

using namespace mlir;
using namespace tpu_mlir;
using namespace tpu_mlir::helper;

Value top::ReshapeOp::lowering_int8_bm1684x(bool asymmetric) {
  return lowering_common_int8<tpu::ReshapeOp>(getOperation(), asymmetric);
}

Value top::ReshapeOp::lowering_f32_bm1684x() {
  return lowering_common_float<tpu::ReshapeOp>(getOperation());
}

Value top::ReshapeOp::lowering_bf16_bm1684x() {
  return lowering_common_float<tpu::ReshapeOp, BFloat16Type>(getOperation());
}

Value top::ReshapeOp::lowering_f16_bm1684x() {
  return lowering_common_float<tpu::ReshapeOp, Float16Type>(getOperation());
}

Value top::ReshapeOp::lowering_quant_bm1684x() {
  return lowering_common<tpu::ReshapeOp>(getOperation(), output().getType());
}
