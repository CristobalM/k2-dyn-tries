#ifndef K2TREE_DARROY_ADAPTER
#define K2TREE_DARROY_ADAPTER
struct trieNode;
struct TreeInfo;

class K2TreeDarroyAdapter{

  int treeDepth;
  int maxNodes;


  trieNode *t;
  TreeInfo *treeInfo;
  public:

  K2TreeDarroyAdapter(int depth, int maxNodes);
  ~K2TreeDarroyAdapter();

  void insert(unsigned long col, unsigned long row);
  bool has(unsigned long col, unsigned long row);
  void debugPrint();

};

#endif