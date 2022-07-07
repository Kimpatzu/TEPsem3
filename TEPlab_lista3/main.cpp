#include <iostream>
#include "CNodeStatic.h"
#include "CTreeStatic.h"
#include "CNodeDynamic.h"
#include "CTreeDynamic.h"

int main() {
    //CNodeStatic c_node;
    //c_node.v_tree_test();
    CTreeDynamic c_tree;
    CNodeDynamic *c_root = c_tree.pcGetRoot();
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
    c_tree.vPrintTree();
    CTreeDynamic c_tree2;
    CNodeDynamic *c_root2 = c_tree2.pcGetRoot();
    c_root2->vAddNewChild();
    c_root2->vAddNewChild();
    c_root2->pcGetChild(0)->vSetValue(31);
    c_root2->pcGetChild(1)->vSetValue(32);
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue(311);
    c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue(312);
    c_root2->pcGetChild(1)->vAddNewChild();
    c_root2->pcGetChild(1)->vAddNewChild();
    c_root2->pcGetChild(1)->pcGetChild(0)->vSetValue(321);
    c_root2->pcGetChild(1)->pcGetChild(1)->vSetValue(322);
    c_tree2.vPrintTree();
    CTreeDynamic c_tree3;
    c_tree3 = c_tree3.merge_trees(c_tree,c_tree2);
    c_tree3.pcGetRoot()->vPrintAllBelow();
    return 0;
}
