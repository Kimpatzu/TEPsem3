#include <vector>
#include <iostream>
#include "CNodeStatic.h"
#include <stdlib.h>

CNodeStatic::CNodeStatic() {
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic() {

}

CNodeStatic *CNodeStatic::getRandomValueNode(){
    CNodeStatic newRandValNode;
    newRandValNode.i_val = rand() % 1000 + 1;
    return  &newRandValNode;
}

void CNodeStatic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber() {
    return  v_children.size();
}

void CNodeStatic::vAddNewChild() {
    CNodeStatic newChild;
    newChild.pc_parent_node = this;
    v_children.push_back(CNodeStatic());
}

void CNodeStatic::vAddNewChild(CNodeStatic &pc_newChild) {
    pc_newChild.pc_parent_node = this;
    v_children.push_back(pc_newChild);
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
    if (iChildOffset >= iGetChildrenNumber()){
        return NULL;
    } else {
        return &v_children.at(iChildOffset);
    }
}

void CNodeStatic::vPrint() {
    std::cout<<" "<<i_val;
}
void CNodeStatic::vPrintAllBelow() {
    vPrint();
    for (int i=0; i<iGetChildrenNumber(); i++){
        v_children.at(i).vPrintAllBelow();
    }
}


void CNodeStatic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL) {
        pc_parent_node->vPrintUp();
    }
}

int CNodeStatic::iGetVal() {
    return i_val;
}


void CNodeStatic::v_tree_test() {
    CNodeStatic c_root;
    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);
    c_root.vPrintAllBelow();
}
