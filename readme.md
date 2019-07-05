# libnms

We always need nms when writting a detector. But nms should be most low latency, so we make it be a shared lib, you can link to nms in your project and directly call it through header files.
Since every framework have their own types, we think it would be better integrate nms with different framework. For instance:

- `libtorch` has their `at::Tensor` to operate on;
- `caffe` has `Blob` to operate on;
- `ncnn` has it's own `tensor` as outputs;

So the easiest way to using nms, simple copy need headers and srcs into your target project, and directly make it.

Currently we still have some todos on libnms:

- [x] fast soft-nms on CPU;
- [ ] to support softnms in GPU;
- [ ] maybe add python wrapper in the future;
- [ ] add some using examples in readme.


## Build

to build libnms, direct run:

```
./make.sh
```
Once built you can link to your project in CMakeLists.txt