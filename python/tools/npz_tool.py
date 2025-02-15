#!/usr/bin/env python3
# ==============================================================================
#
# Copyright (C) 2022 Sophgo Technologies Inc.  All rights reserved.
#
# TPU-MLIR is licensed under the 2-Clause BSD License except for the
# third-party components.
#
# ==============================================================================

from numpy_helper import *
npz_tool_func = {
    "compare": npz_compare,
    "visualize_diff": npz_visualize_diff,
    'dump':npz_dump,
    "extract": npz_extract,
    "rename": npz_rename,
    "to_bin": npz_to_bin,
    "int8_to_fp32": npz_int8_to_fp32,
    "bf16_to_fp32": npz_bf16_to_fp32,
    "tranpose": npz_transpose,
    "get_shape": get_npz_shape,
    "to_dat": npz_to_dat,
}

def main():
    args_list = sys.argv
    if len(args_list) < 2:
        print("Usage: {} {} ".format(args_list[0], npz_tool_func.keys()))
        exit(-1)

    def NoneAndRaise(func):
        raise RuntimeError("No support {} Method".format(func))

    npz_tool_func.get(args_list[1], lambda x: NoneAndRaise(args_list[1]))(args_list[2:])


if __name__ == "__main__":
    main()
