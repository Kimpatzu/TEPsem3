
#ifndef TEPLAB_LISTA3_CTREESTATIC_H
#define TEPLAB_LISTA3_CTREESTATIC_H
#include "CNodeStatic.h"

class CTreeStatic {
public:
    CTreeStatic();
    ~CTreeStatic();

    CNodeStatic *pcGetRoot();
    void vPrintTree();
    CTreeStatic merge_trees(CTreeStatic &first, CTreeStatic &second);
    CTreeStatic *newRandValRootTree();
    void deleteRoot();
private:
    CNodeStatic c_root;
};


#endif //TEPLAB_LISTA3_CTREESTATIC_H
