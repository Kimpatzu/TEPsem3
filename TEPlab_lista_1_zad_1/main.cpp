#include <iostream>


void v_alloc_table_add_5(int iSize)
{
    if (iSize<=0)
    {
        std::cout << "Nieprawidlowa wartosc rozmiaru tablicy" <<std::endl;
    }
    else
    {
        int *i_table;
        i_table = new int[iSize];
        for (int i=0; i<iSize; i++){
            i_table[i]=i+5;
        }
        for (int i=0; i<iSize; i++)
        {
            std::cout << " | ";
            std::cout <<i_table[i];
        }
        delete[] i_table;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    v_alloc_table_add_5(4);
    return 0;
}
