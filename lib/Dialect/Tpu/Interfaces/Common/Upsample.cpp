//===----------------------------------------------------------------------===//
//
// Copyright (C) 2022 Sophgo Technologies Inc.  All rights reserved.
//
// TPU-MLIR is licensed under the 2-Clause BSD License except for the
// third-party components.
//
//===----------------------------------------------------------------------===//

#include "tpu_mlir/Dialect/Tpu/IR/TpuOps.h"
#include "tpu_mlir/Support/Dnnl/Dnnl.h"
#include "tpu_mlir/Support/Helper/Module.h"
#include "tpu_mlir/Support/Helper/Quant.h"
#include "tpu_mlir/Support/MathUtils.h"

using namespace tpu_mlir;
using namespace tpu_mlir::helper;
using namespace mlir;

LogicalResult tpu::UpsampleOp::init(InferenceParameter &p) { return success(); }
void tpu::UpsampleOp::deinit(InferenceParameter &p) {}

LogicalResult tpu::UpsampleOp::inference(InferenceParameter &p) {
  int64_t n, c, ih, iw;
  Module::getNCHW(input(), n, c, ih, iw);
  int64_t oh = ih * scale_h();
  int64_t ow = iw * scale_w();
  auto num_elem = Module::getNumElements(output());
#pragma omp parallel for schedule(static, omp_schedule(num_elem))
  for (int64_t d0 = 0; d0 < n; d0++) {
    for (int64_t d1 = 0; d1 < c; d1++) {
      for (int64_t d2 = 0; d2 < oh; d2++) {
        for (int64_t d3 = 0; d3 < ow; d3++) {
          int64_t idx_o = (((d0 * c + d1) * oh) + d2) * ow + d3;
          int64_t idx_i =
              ((((d0 * c + d1) * ih) + d2 / scale_h())) * iw + (d3 / scale_w());
          p.outputs[0][idx_o] = p.inputs[0][idx_i];
        }
      }
    }
  }

  if (do_relu()) {
    auto limit = relu_limit().convertToDouble();
    function_relu(p.outputs[0], p.outputs[0], num_elem, limit);
  }
  return success();
}

LogicalResult tpu::UpsampleOp::BackwardH(int64_t &in_idx, int64_t &in_slice,
                                         int64_t out_idx, int64_t out_slice) {
  auto unit = scale_h();
  if (out_idx % unit || out_slice % unit) {
    return failure();
  }
  in_idx = out_idx / unit;
  in_slice = out_slice / unit;
  return success();
}
