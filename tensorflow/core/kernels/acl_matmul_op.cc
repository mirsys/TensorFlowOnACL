/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

// See docs in ../ops/math_ops.cc.
#if defined(USE_ACL)

#define EIGEN_USE_THREADS
#include "tensorflow/core/kernels/acl_matmul_op.h"

namespace tensorflow {

typedef Eigen::ThreadPoolDevice CPUDevice;
typedef Eigen::GpuDevice GPUDevice;

#define REGISTER_CPU(T)                                            \
  REGISTER_KERNEL_BUILDER(                                         \
      Name("AclMatMul").Device(DEVICE_CPU).TypeConstraint<T>("T"), \
      AclMatMulOp<CPUDevice, T>);

#define REGISTER_GPU(T)                                            \
  REGISTER_KERNEL_BUILDER(                                         \
      Name("AclMatMul").Device(DEVICE_GPU).TypeConstraint<T>("T"), \
      AclMatMulOp<GPUDevice, T>);

TF_CALL_float(REGISTER_CPU);
TF_CALL_float(REGISTER_GPU);
}  // namespace tensorflow

#endif //USE_ACL