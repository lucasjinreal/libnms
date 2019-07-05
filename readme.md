# libnms

We always need nms when writting a detector. But nms should be most low latency, so we make it be a shared lib, you can link to nms in your project and directly call it through header files.

Currently we still have some todos on libnms:

- [ ] to support softnms in GPU;
- [ ] maybe add python wrapper in the future;
- [ ] add some using examples in readme.


## Build

to build libnms, direct run:

```
./make.sh
```
Once built you can link to your project in CMakeLists.txt