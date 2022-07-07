//
// Created by 48884 on 04.11.2021.
//

#include <iostream>
#include "CTable.h"

CTable::CTable() {
    this->sName = defaultName;
    this->iTableLen = defaultSize;
    this->iTab = new int[this->iTableLen];
}

CTable::CTable(std::string sName, int iTableLen) {
    this->sName = sName;
    this->iTableLen = iTableLen;
    this->iTab = new int[iTableLen];
}

CTable::CTable(const CTable &pcOther){
    this->sName = pcOther.sName + "_copy";
    this->iTableLen = pcOther.iTableLen;
    this->iTab = new int[iTableLen];
    for (int i=0; i<iTableLen; i++){
        this->iTab[i] = pcOther.iTab[i];
    }

}

CTable::~CTable(){
    std::cout<<"usuwam: "<<"'"<<this->sName<<"'";
    delete(this->iTab);
}

void CTable::vSetName(std::string sName){
    this->sName = sName;
}

bool CTable::bSetNewSize(int iTableLen){
    if (iTableLen<1){
        return false;
    } else {
        this->iTableLen = iTableLen;
        delete(this->iTab);

        this->iTab = new int[this->iTableLen];
        return true;
    }
}

CTable *CTable::pcClone(){
    CTable *newITab = new CTable(*this);
    return newITab;
}

void CTable::v_mod_table(CTable *pcTab, int newSize){
    if (newSize<1){
        return;
    } else {
        this->iTableLen = newSize;
        delete(this->iTab);

        this->iTab = new int[this->iTableLen];
        return;
    }
}

void CTable::operator=(CTable &pcOther){
    iTab = pcOther.iTab;
    iTableLen = pcOther.iTableLen;
}

CTable CTable::operator+(CTable &pcOther) {
    int *newITab = new int[this->iTableLen + pcOther.iTableLen];
    int i=0;
    while(i<this->iTableLen){
        newITab[i]= this->iTab[i];
        i++;
    }
    for (int j=0; j<pcOther.iTableLen; j++){
        newITab[i] = pcOther.iTab[j];
        i++;
    }
    CTable returnCTable;
    returnCTable.iTableLen = this->iTableLen + pcOther.iTableLen;
    returnCTable.iTab = newITab;
    return  returnCTable;
}

CTable CTable::operator>>(int k) {      //przesuniecie w prawo
    if (k>iTableLen || (-k)>iTableLen){
        std::cout<<"out of bounds ";
    } else if (k==0){
        CTable helpcTab(*this);
        return helpcTab;
    } else if (k>0){
        CTable helpcTab(*this);
        for (int i=iTableLen+1; i>=k; i--){
            helpcTab.iTab[i] = iTab[i-k];
        }
        for (int i=0; i<k; i++){
            helpcTab.iTab[i] = iTab[iTableLen-k+i];
        }
        return helpcTab;
    } else if (k<0){
        CTable helpcTab(*this);
        return  (helpcTab <<(-k));
    }

}

CTable CTable::operator<<(int k) {      //przesuniecie w lewo
    if (k>iTableLen || (-k)>iTableLen){
        std::cout<<"out of bounds ";
    } else if (k==0){
        CTable helpcTab(*this);
        return helpcTab;
    } else if (k>0){
        CTable helpcTab(*this);
        for (int i=0; i<iTableLen-k; i++){
            helpcTab.iTab[i] = iTab[i+k];
        }
        for (int i=0; i<k; i++){
            helpcTab.iTab[iTableLen-k+i] = iTab[i];
        }
        return helpcTab;
    } else if (k<0){
        CTable helpcTab(*this);
        return (helpcTab <<(-k));
    }
}

void CTable::vSetValueAt(int iOffset, int iNewVal){
    if (iOffset >= this->iTableLen || iOffset < 0){
        return;
    } else {
        this->iTab[iOffset] = iNewVal;
    }
}

void CTable::vPrint() {
    for (int j=0; j<this->iTableLen; j++){
        std::cout<<this->iTab[j]<<" ";
    }
    std::cout<<std::endl;
}