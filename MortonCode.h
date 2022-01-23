#ifndef MORTON_CODE_H
#define MORTON_CODE_H

#include <cstdint>

struct MortonCode {
  uint8_t *container;
  int size;
};

MortonCode convertCoordinatesToMortonCode(unsigned long col, unsigned long row,
                                          int treeDepth);

#endif
