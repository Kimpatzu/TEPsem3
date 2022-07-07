
#ifndef TEPLAB_LISTA5_CTAB_H
#define TEPLAB_LISTA5_CTAB_H
#define iDefSize 100

class CTab
{
public:
    CTab() {
        pi_tab = new int[iDefSize]; i_size = iDefSize;
    }
    CTab(const CTab &cOther);
    CTab(CTab &&cOther);
    ~CTab();

    bool bSetSize(int iNewSize);

    int iGetSize() {
        return(i_size);
    }

    CTab operator=(const CTab &cOther);
    CTab operator=(CTab &&cOther);

private:
    void v_copy(const CTab &cOther);
    int *pi_tab;
    int i_size;
};


#endif //TEPLAB_LISTA5_CTAB_H
