#include <iostream>
#include "CNodeDynamic.h"

CNodeDynamic::CNodeDynamic() {
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeDynamic::CNodeDynamic(CNodeDynamic *pcOtherNode) {
    i_val = pcOtherNode->i_val;
    *pc_parent_node = pcOtherNode->pc_parent_node;
    for (int i=0; i<pcOtherNode->iGetChildrenNumber(); i++){
        v_children.push_back(pcOtherNode->pcGetChild(i));
    }
}

CNodeDynamic::~CNodeDynamic() {
    for (int i=0; i<v_children.size(); i++) {
        if (v_children[i] != NULL) {
            delete v_children[i];
        }
    }
}

void CNodeDynamic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeDynamic::iGetChildrenNumber() {
    return v_children.size();
}

void CNodeDynamic::vAddNewChild() {
    CNodeDynamic *newChild = new CNodeDynamic;
    newChild->pc_parent_node = this;
    v_children.push_back(newChild);
}

void CNodeDynamic::vAddNewChild(CNodeDynamic *pcOtherNode) {
    pcOtherNode->pc_parent_node = this;
    v_children.push_back(pcOtherNode);
}

CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
    if (iChildOffset < iGetChildrenNumber()) {
        return v_children.at(iChildOffset);
    }
    return NULL;
}

void CNodeDynamic::vPrint() {
    std::cout<<" "<<i_val;
}

int CNodeDynamic::iGetVal(){
    return i_val;
}

void CNodeDynamic::vPrintAllBelow() {
    vPrint();
    for (int i=0; i<v_children.size(); i++) {
        if (v_children.at(i) != NULL) {
            v_children.at(i)->vPrintAllBelow();
        }
    }
}

