# libnms

We always need nms when writting a detector. But nms should be most low latency, so we make it be a shared lib, you can link to nms in your project and directly call it through header files.
Since every framework have their own types, we think it would be better integrate nms with different framework. For instance:

- `libtorch` has their `at::Tensor` to operate on;
- `caffe` has `Blob` to operate on;
- `ncnn` has it's own `tensor` as outputs;

So the easiest way to using nms, simple copy need headers and srcs into your target project, and directly make it.

Currently we still have some todos on libnms:

- [x] libtorch supported;
- [x] fast soft-nms on CPU;
- [x] dedicated usage of libnms in libtorch as an example;
- [ ] to support softnms in GPU;
- [ ] caffe nms to be add;
- [ ] ncnn nms to be add;


## Usage

Take libtorch nms as an example. In your project, you have your detectors simply copy `./nms` all files to your include folder, add them as library in cmake:

```
add_definitions(-D WITH_CUDA)

add_definitions(-D__CUDA_NO_HALF_OPERATORS__)
CUDA_ADD_LIBRARY(
            aosdetector
            SHARED
            src/priorbox.cc
            src/detector.cc
            include/nms/cpu/nms_cpu.cpp
            include/nms/cuda/nms_cuda.cu
)
```

You should using `WITH_CUDA` flag to open nms GPU support. And them using `CUDA_ADD_LIBRARY` in cmake to compile `.cu` codes.

In your src file, you can call nms like this:

```
torch::Tensor keep_idxes = nms(c_boxes, c_scores, 0.2);
```

this will return keep_idxes after nms.




## Copyright

this lib opensourced by Jin Fagang under Apache License.
