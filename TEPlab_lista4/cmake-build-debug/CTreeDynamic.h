#ifndef TEPLAB_LISTA4_CTREEDYNAMIC_H
#define TEPLAB_LISTA4_CTREEDYNAMIC_H
#include "CNodeDynamic.h"
#include "stdlib.h"

template <typename T> class CTreeDynamic {
public:
    CTreeDynamic();
    ~CTreeDynamic();

    CNodeDynamic<T> *pcGetRoot();
    void vPrintTree();
    CTreeDynamic pcGetNewRandRootTree();
    CTreeDynamic merge_trees(CTreeDynamic &first,  CTreeDynamic &second);

private:
    CNodeDynamic<T> *pc_root;
};

template <typename T>
CTreeDynamic<T>::CTreeDynamic() {
    pc_root = new CNodeDynamic<T>();
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic() {
    delete pc_root;
}

template <typename T>
CNodeDynamic<T> *CTreeDynamic<T>::pcGetRoot() {
    return pc_root;
}

template <typename T>
void CTreeDynamic<T>::vPrintTree() {
    pc_root->vPrintAllBelow();
}

template <typename T>
CTreeDynamic<T> CTreeDynamic<T>::pcGetNewRandRootTree() {
    CTreeDynamic newTree;
    newTree.pc_root->vSetValue(rand() % 1000 + 1);
    return CTreeDynamic(newTree);
}

template <typename T>
CTreeDynamic<T> CTreeDynamic<T>::merge_trees(CTreeDynamic &first, CTreeDynamic &second) {
    CTreeDynamic newTree;
    newTree = new CTreeDynamic(pcGetNewRandRootTree());
    newTree.pcGetRoot()->vAddNewChild(first.pcGetRoot());
    newTree.pcGetRoot()->vAddNewChild(second.pcGetRoot());
    return newTree;
}

#endif //TEPLAB_LISTA4_CTREEDYNAMIC_H
