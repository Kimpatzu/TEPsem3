
#include "CTreeStatic.h"
#include <vector>
#include <stdlib.h>


CTreeStatic::CTreeStatic() {

}

CTreeStatic::~CTreeStatic() {

}

CNodeStatic *CTreeStatic::pcGetRoot() {
    return(&c_root);
}

void CTreeStatic::vPrintTree() {
    c_root.vPrintAllBelow();
}


