#include <iostream>
#include "CTable.h"

int main() {
    //CTable c_tab_0, c_tab_1;
    //c_tab_0.bSetNewSize(6);
    //c_tab_1.bSetNewSize(4);
/* initialize table */
    //c_tab_1.vSetValueAt(2,123);
    //c_tab_0.vSetValueAt(1,15);
    //c_tab_0.vPrint();
    //c_tab_1.vPrint();
    //(c_tab_0+c_tab_1).vPrint();
    CTable cTab1, cTab2;
    cTab1.bSetNewSize(6);
    cTab1.vSetValueAt(0,4);
    cTab1.vSetValueAt(1,2);
    cTab1.vSetValueAt(2,0);
    cTab1.vSetValueAt(3,5);
    cTab1.vSetValueAt(4,0);
    cTab1.vSetValueAt(5,5);
    cTab1.vPrint();
    (cTab1 << -2).vPrint();
    return 0;
}
