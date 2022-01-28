#include "K2TreeDarroyAdapter.h"
#include "MortonCode.h"
#include "treeBlock.h"

#include <iostream>
#include <cmath>

K2TreeDarroyAdapter::K2TreeDarroyAdapter(int depth, int maxNodes)
        : treeDepth(depth), maxNodes(maxNodes) {
    t = new trieNode();
    treeInfo = new TreeInfo;
    treeInfo->Nt = maxNodes;
    treeInfo->N1 = 4;
    treeInfo->sizeArray = new uint16_t[maxNodes + 1]();
    static constexpr double alpha = 0.99;
    for (int i = 0; i <= maxNodes; ++i) {
        if (i > treeInfo->N1)
            treeInfo->N1 =
                    4 * (((uint16_t) std::ceil((double) treeInfo->N1 / alpha) + 3) / 4);
        treeInfo->sizeArray[i] = treeInfo->N1;
    }
}

K2TreeDarroyAdapter::~K2TreeDarroyAdapter() {
    if (t->block)
        reinterpret_cast<treeBlock *>(t->block)->freeTreeBlock();
    delete t;
    delete[] treeInfo->sizeArray;
    delete treeInfo;
}

static void debugPrintMortonCode(unsigned long col, unsigned long row,
                                 MortonCode &mortonCode) {
    std::cout << "morton code for (" << col << ", " << row << "): ";
    for (int i = 0; i < mortonCode.size; i++) {
        std::cout << (int) mortonCode.container[i];
    }
    std::cout << std::endl;
}

void K2TreeDarroyAdapter::insert(unsigned long col, unsigned long row) {
    auto mortonCode = convertCoordinatesToMortonCode(col, row, treeDepth);
    // debugPrintMortonCode(col, row, mortonCode);

    insertTrie(treeInfo, t, mortonCode.container, mortonCode.size+1, treeDepth);
}

bool K2TreeDarroyAdapter::has(unsigned long col, unsigned long row) {
    auto mortonCode = convertCoordinatesToMortonCode(col, row, treeDepth);
    return isEdgeTrie(t, mortonCode.container, mortonCode.size, treeDepth);
}