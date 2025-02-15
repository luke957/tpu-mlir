//===----------------------------------------------------------------------===//
//
// Copyright (C) 2022 Sophgo Technologies Inc.  All rights reserved.
//
// TPU-MLIR is licensed under the 2-Clause BSD License except for the
// third-party components.
//
//===----------------------------------------------------------------------===//

#include "tpu_mlir/Dialect/Top/IR/TopOps.h"

using namespace tpu_mlir;
using namespace mlir;

int64_t top::ConcatOp::getFLOPs() { return 0; }

LogicalResult top::ConcatOp::init(InferenceParameter &p) { return success(); }
void top::ConcatOp::deinit(InferenceParameter &p) {}

LogicalResult top::ConcatOp::inference(InferenceParameter &p) {
  auto axis_ = axis();
  auto op0_shape = inputs()[0].getType().cast<RankedTensorType>().getShape();

  int64_t high = 1;
  for (int64_t i = 0; i < axis_; ++i)
    high *= op0_shape[i];
  // Split the elements to high and low parts and view the lower parts as a
  // single one. We can merge those elemnets more efficiently.
  // [a,b,c,d] -> [a*b, c*d] \
  //      ^                   | ---> [a*b, c*d + e*d] --> [a,b, c+e, d]
  // [a,b,e,d] -> [a*b, e*d] /                                  ^^^
  //      ^
  SmallVector<int64_t> tailNum(inputs().size());
  for (auto idt : llvm::enumerate(inputs())) {
    tailNum[idt.index()] =
        idt.value().getType().cast<RankedTensorType>().getNumElements() / high;
  }
  auto out_p = p.outputs[0];
  for (int64_t i = 0; i < high; ++i) {
    for (auto idt : llvm::enumerate(tailNum)) {
      memcpy(out_p, p.inputs[idt.index()] + i * idt.value(),
             idt.value() * sizeof(float));
      out_p += idt.value();
    }
  }

  return success();
}
