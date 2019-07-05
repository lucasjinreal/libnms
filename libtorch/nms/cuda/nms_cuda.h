#pragma once
#include <c10/cuda/CUDAGuard.h>
#include <torch/extension.h>

at::Tensor nms_cuda(
    const at::Tensor& dets,
    const at::Tensor& scores,
    const float iou_threshold);