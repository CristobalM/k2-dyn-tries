
#include "MortonCode.h"
#include <iostream>


MortonCode convertCoordinatesToMortonCode(unsigned long col, unsigned long row,
                                        int treeDepth){

  MortonCode out;
  out.container = (uint8_t *)calloc(treeDepth, sizeof(out.container));

  unsigned long halfLevel;
  if (treeDepth > 64) {
    std::cerr << "K2tree not implemented for depths higher than 64"
              << std::endl;
    exit(1);
  } else if (treeDepth == 64) {
    halfLevel = 1UL << 63UL;
  } else {
    halfLevel = (1UL << (unsigned long)(treeDepth - 1));
  }
  uint32_t mcPosition = 0;
  while (halfLevel > 0) {
    uint32_t quadrant;

    if (col >= halfLevel && row >= halfLevel) {
      quadrant = 3;
    } else if (col >= halfLevel && row < halfLevel) {
      quadrant = 2;
    } else if (col < halfLevel && row >= halfLevel) {
      quadrant = 1;
    } else {
      quadrant = 0;
    }

    col %= halfLevel;
    row %= halfLevel;
    halfLevel >>= 1UL;

    out.container[mcPosition++] = quadrant;
  }
  out.size = mcPosition;
  return out;
}
