
#ifndef TEPLAB_LISTA3_CNODEDYNAMIC_H
#define TEPLAB_LISTA3_CNODEDYNAMIC_H
#include <vector>

class CNodeDynamic {
public:
    CNodeDynamic();
    CNodeDynamic(CNodeDynamic *pcOtherNode);
    ~CNodeDynamic();

    void vSetValue(int NewVal);
    int iGetChildrenNumber();
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic *pcOtherNode);
    CNodeDynamic *pcGetChild(int iChildOffset);
    CNodeDynamic *pcGetParentNode();

    void vPrint();
    void vPrintAllBelow();
    int iGetVal();

private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;

};


#endif //TEPLAB_LISTA3_CNODEDYNAMIC_H
