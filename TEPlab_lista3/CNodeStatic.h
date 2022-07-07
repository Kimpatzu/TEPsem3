#include <iostream>
#include <vector>
#ifndef TEPLAB_LISTA3_CNODESTATIC_H
#define TEPLAB_LISTA3_CNODESTATIC_H
#include <vector>

class CNodeStatic {

public:
    CNodeStatic();
    ~CNodeStatic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();
    void vAddNewChild();
    void vAddNewChild(CNodeStatic &pc_newChild);
    CNodeStatic *pcGetChild(int iChildOffset);
    CNodeStatic *getRandomValueNode();

    int iGetVal();
    std::vector<CNodeStatic> getChildrenVector();
    void vPrint();
    void vPrintAllBelow();
    void vPrintUp();

    void v_tree_test();

private:
    std::vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;
};


#endif //TEPLAB_LISTA3_CNODESTATIC_H
