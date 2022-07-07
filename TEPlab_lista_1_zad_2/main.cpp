#include <iostream>

#define defaultSize 5
#define defaultName "DefName"

class CTable{
public:
    std::string sName;
    int iTableLen;
    int *iTab;

    CTable(){
        this->sName = defaultName;
        this->iTableLen = defaultSize;
        this->iTab = new int[this->iTableLen];
    }
    CTable(std::string sName, int iTableLen){
        this->sName = sName;
        this->iTableLen = iTableLen;
        this->iTab = new int[iTableLen];
    }
    CTable(CTable &pcOther){
        this->sName = pcOther.sName + "_copy";
        this->iTableLen = pcOther.iTableLen;
        this->iTab = pcOther.iTab;
    }
    ~CTable(){
        std::cout<<"usuwam: "<<"'"<<this->sName<<"'";
        delete(this->iTab);
    }
    void vSetName(std::string sName){
        this->sName = sName;
    }
    bool bSetNewSize(int iTableLen){
        if (iTableLen<1){
            return false;
        } else {
            this->iTableLen = iTableLen;
            delete(this->iTab);

            this->iTab = new int[this->iTableLen];
            return true;
        }
    }
    CTable *pcClone(){
        CTable *newITab = new CTable(*this);
        return newITab;
    }
    void v_mod_table(CTable *pcTab, int newSize){
        if (newSize<1){
            return;
        } else {
            this->iTableLen = newSize;
            delete(this->iTab);

            this->iTab = new int[this->iTableLen];
            return;
        }
    }
    void v_mod_table(CTable pcTab, int newSize){
        if (newSize<1){
            return;
        } else {
            this->iTableLen = newSize;
            delete(this->iTab);

            this->iTab = new int[this->iTableLen];
            return;
        }
    }

};

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeX <=0 || iSizeY <=0 ){
        std::cout << "Niewlasciwa wartosc rozmiaru tablicy" <<std::endl;
        return false;
    } else {
        *piTable =  new int*[iSizeX];
        for (int i=0; i<iSizeX; i++) {
            (*piTable)[i] = new int[iSizeY];
            for (int j=0; j<iSizeY; j++){
                (*piTable)[i][j] = 2;
            }
        }
        return true;
    }
}

bool b_dealloc_table_2_dim(int ***piTable, int iSizeX){
    if (iSizeX <=0){
        std::cout << "Niewlasciwa wartosc rozmiaru tablicy" <<std::endl;
        return false;
    } else {
        for (int i=0; i<iSizeX; i++){
            delete((*piTable)[i]);
        }
        delete(*piTable);
        return true;
    }
}


int main() {
    int **pi_table;
    std::cout<<b_alloc_table_2_dim(&pi_table,5,3)<<std::endl;
    for (int i=0; i<5; i++){
        for (int j=0; j<3; j++){
            std::cout<<(pi_table)[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<b_dealloc_table_2_dim(&pi_table,5);
    CTable cTable;
    std::cout<<cTable.sName<<std::endl;
    cTable.vSetName("myCTable");
    std::cout<<cTable.sName<<std::endl;
    int *iTab = new int[2];
    iTab[0] = 1;
    iTab[1] = 2;
    return 0;
}
