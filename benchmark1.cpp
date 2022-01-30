
#include "K2TreeDarroyAdapter.h"
#include <iostream>
#include <utility>
#include <vector>

#include <chrono>


static void benchmark1(int size){
  K2TreeDarroyAdapter k2tree(20, 256);

  auto start = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < size; i++){
    k2tree.insert(i,i);
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  auto microseconds = duration.count();
  std::cout << "Insertion Benchmark 1 took: " << microseconds << " microseconds, for input size = " << size
  << ", microsecs/point = " << (double)microseconds/(double)size << std::endl;


  start = std::chrono::high_resolution_clock::now();
  int count = 0;
  for(int i = 0; i < size; i++){
    bool hasIt = k2tree.has(i,i);
    if(hasIt) count++;
  }
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  microseconds = duration.count();
  std::cout << "Lookup Benchmark 1 took: " << microseconds << " microseconds, for input size = " << size
  << ", microsecs/point = " << (double)microseconds/(double)size << ", total count: " << count << std::endl;

  k2tree.debugPrint();

}

int main(int argc, char **argv){

  if(argc < 2){
    std::cerr << "missing size parameter" << std::endl;
    exit(1);
  }

  int size = std::stoi(argv[1]);
  benchmark1(size);


}