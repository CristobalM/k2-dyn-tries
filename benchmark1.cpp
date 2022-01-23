
#include "K2TreeDarroyAdapter.h"
#include <iostream>
#include <utility>
#include <vector>

#include <chrono>


static void benchmark1(){
  K2TreeDarroyAdapter k2tree(32, 256);

  auto start = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < 1000; i++){
    std::cout << "inserting (" << i << ", " << i << ")" << std::endl;
    k2tree.insert(i,i);
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  std::cout << "Benchmark 1 took: " << duration.count() << " microseconds" << std::endl;

}

int main(){

  benchmark1();


}