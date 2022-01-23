#include "K2TreeDarroyAdapter.h"
#include <iostream>
#include <utility>
#include <vector>

static void print_debug(K2TreeDarroyAdapter &k2tree, int side){
  for(int i = 0; i < side; i++){
    for(int j = 0; j < side; j++){
      auto hasIt = k2tree.has(j, i);
      std::cout << (hasIt ? '1' : '0') << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  std::cout << "going to construct" << std::endl;
  K2TreeDarroyAdapter k2tree(32, 128);
  for (int i = 0; i < 10; i++) {
    std::cout << "Inserting (" << i << ", " << i << ") ..." << std::endl;
    k2tree.insert(i, i);
    std::cout << "Inserted (" << i << ", " << i << ")" << std::endl;
    
    std::cout << "matrix:" << std::endl;
    print_debug(k2tree, 8);
  }

  std::vector<std::pair<int, int>> extras = {
          {1, 0},
          {0, 1},
          {7,0},
          {0, 7},
  };

  for (auto &p: extras) {
    std::cout << "Inserting (" << p.first << ", " << p.second << ") ..." << std::endl;
    k2tree.insert(p.first, p.second);
    std::cout << "Inserted (" << p.first << ", " << p.second << ")" << std::endl;
    
    std::cout << "matrix:" << std::endl;
    print_debug(k2tree, 8);
  }


  for (int i = 0; i < 10; i++) {
    bool hasIt = k2tree.has(i, i);
    std::cout << "Has (" << i << ", " << i << ") ?: " << (hasIt ? "YES" : "NO") << std::endl;
  }
}