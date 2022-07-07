//
// Created by 48884 on 04.11.2021.
//

#ifndef TEPLAB_LISTA2_CTABLE_H
#define TEPLAB_LISTA2_CTABLE_H

#define defaultSize 5
#define defaultName "DefName"

class CTable {

public:
    CTable();
    CTable(std::string sName, int iTableLen);
    CTable(const CTable &pcOther);
    ~CTable();

    void vSetName(std::string sName);
    bool bSetNewSize(int iTableLen);
    CTable *pcClone();
    void v_mod_table(CTable *pcTab, int newSize);
    void operator=(CTable &pcOther);
    CTable operator+(CTable &pcOther);
    CTable operator>>(int k);
    CTable operator<<(int k);
    void vSetValueAt(int iOffset, int iNewVal);
    void vPrint();


private:
    std::string sName;
    int iTableLen;
    int *iTab;

};


#endif //TEPLAB_LISTA2_CTABLE_H
