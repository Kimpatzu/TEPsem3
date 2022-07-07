
#ifndef TEPLAB_LISTA5_CMYSMARTPOINTER_H
#define TEPLAB_LISTA5_CMYSMARTPOINTER_H

#include "CRefCounter.h"

template < typename T > class CMySmartPointer {

public:
    CMySmartPointer(T *pcPointer) {
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
    }

    CMySmartPointer(const CMySmartPointer &pcOther) {
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        pc_counter->iAdd();
    }

    ~CMySmartPointer() {
        if (pc_counter->iDec() == 0) {
            delete pc_pointer;
            delete pc_counter;
        }
    }

    CSellData& operator*() {
        return(*pc_pointer);
    }

    CSellData* operator->() {
        return(pc_pointer);
    }

private:
    CRefCounter *pc_counter;
    T *pc_pointer;
};


template <typename T>
CMySmartPointer<T>& CMySmartPointer<T>::operator=(const CMySmartPointer *copy)  {
    if(!(this == copy && this->pc_pointer == copy->pc_pointer)) {
        if (pc_counter->iDec() == 0) {
            delete pc_pointer;
            delete pc_counter;
        }
        this->pc_counter = copy->pc_counter;
        this->pc_pointer = copy->pc_pointer;
        this->pc_counter->iAdd();
    }
    return *this;
}

template <typename T>
template <typename R>
CMySmartPointer<R> CMySmartPointer<T>::My_Dynamic_Cast(){
    return CMySmartPointer<R>(*this);
}


#endif //TEPLAB_LISTA5_CMYSMARTPOINTER_H
