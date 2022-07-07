#include <iostream>
#include "CTab.h"

CTab::CTab(const CTab &cOther) {
    v_copy(cOther);
}

CTab::~CTab() {
    if (pi_tab != NULL) {
        delete pi_tab;
    }
}

CTab CTab::operator=(const CTab &cOther) {
    if (pi_tab != NULL) {
        delete pi_tab;
    }
    v_copy(cOther);
    return *this;
}

void CTab::v_copy(const CTab &cOther) {
    pi_tab = new int[cOther.i_size];
    i_size = cOther.i_size;
    for (int i = 0; i < cOther.i_size; i++) {
        pi_tab[i] = cOther.pi_tab[i];
    }
}

CTab::CTab(CTab &&cOther) {
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
}

CTab CTab::operator=(CTab &&cOther) {
    if(this->pi_tab != NULL) {
        delete (this->pi_tab);
    }
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    return (*this);
}

bool CTab::bSetSize(int newSize) {
    if(newSize < 1 || newSize > 500) {
        return false;
    }
    this->i_size = newSize;
    delete(this->pi_tab);
    this->pi_tab = new int[this->i_size];
    return true;

}