#include <iostream>
#include <vector>
#include "gpu_nms.hpp"


using namespace std;

int main() {
  int num = 3;
  vector<int> keep_idxes(3, 0);
  float arr[] = {
		10, 10, 20, 20, 0.5, 
  		15, 15, 20, 20, 0.3, 
	  	20, 20, 25, 25, 0.1
	};

  float interS = (20 - 15 + 1) * (20 - 15 + 1);
  float Sa = (11 * 11);
  float Sb = (6 * 6);

  std::cout << interS / (Sa + Sb - interS) << std::endl;

 // keep_idxes, num_out, in_boxes, num_in, box_dim, thresh
  nms_gpu(keep_idxes.data(), &num, arr, 3, 5, 0.29, 0);
  std::cout << (num) << std::endl;
  for (int i = 0; i < num; i++) {
    std::cout << keep_idxes[i] << std::endl;
  }
}
