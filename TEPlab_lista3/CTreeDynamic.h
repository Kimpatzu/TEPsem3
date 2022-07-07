
#ifndef TEPLAB_LISTA3_CTREEDYNAMIC_H
#define TEPLAB_LISTA3_CTREEDYNAMIC_H
#include "CNodeDynamic.h"

class CTreeDynamic {
public:
    CTreeDynamic();
    CTreeDynamic(CTreeDynamic *pcOtherTree);
    ~CTreeDynamic();

    CNodeDynamic *pcGetRoot();
    void vPrintTree();
    CTreeDynamic pcGetNewRandRootTree();
    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
    CTreeDynamic merge_trees(CTreeDynamic &first,  CTreeDynamic &second);

private:
    CNodeDynamic *pc_root;
};


#endif //TEPLAB_LISTA3_CTREEDYNAMIC_H
