nvcc --gpu-architecture=compute_61 --gpu-code=compute_61  -DGPU -I/usr/local/cuda/include/ -DCUDNN --compiler-options "-Wall -Wfatal-errors -Ofast -DOPENCV -DGPU -DCUDNN -fPIC" -c nms_kernel.cu -o nms_kernel.o

gcc -shared -o libnms.so nms_kernel.o -L/usr/local/cuda/lib64 -lcuda -lcudart -lcublas -lcurand -lcudnn

g++ -o nms_test nms.cpp -L. -lnms
echo "done! then run ./nms_test"