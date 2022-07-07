
#include "CTreeDynamic.h"
#include "CNodeDynamic.h"
#include <stdlib.h>

CTreeDynamic::CTreeDynamic() {
    pc_root = new CNodeDynamic();
}

CTreeDynamic::CTreeDynamic(CTreeDynamic *pcOtherTree) {
    pc_root = new CNodeDynamic(pcOtherTree->pcGetRoot());
}

CTreeDynamic::~CTreeDynamic() {
    delete pc_root;
}

CNodeDynamic *CTreeDynamic::pcGetRoot() {
    return pc_root;
}

void CTreeDynamic::vPrintTree() {
    pc_root->vPrintAllBelow();
}


CTreeDynamic CTreeDynamic::merge_trees(CTreeDynamic &first, CTreeDynamic &second) {
    CTreeDynamic newTree;
    newTree = new CTreeDynamic(pcGetNewRandRootTree());
    newTree.pcGetRoot()->vAddNewChild(first.pcGetRoot());
    newTree.pcGetRoot()->vAddNewChild(second.pcGetRoot());
    return newTree;
}


CTreeDynamic CTreeDynamic::pcGetNewRandRootTree() {
    CTreeDynamic newTree;
    newTree.pc_root->vSetValue(rand() % 1000 + 1);
    return CTreeDynamic(newTree);
}