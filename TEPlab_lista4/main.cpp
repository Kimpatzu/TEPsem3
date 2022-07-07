#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <typeinfo>

template <typename T, unsigned N>
struct Repeat{
    typedef T ValueType;
    int n = N;
    ValueType operator () (const ValueType& val){
        ValueType acc = val;
        for (int i=1; i<n; i++){
            acc = acc + val;
        }
        return acc;
    }

};

template <class Funct>
struct Mapper {
    std::vector<typename Funct::ValueType>  operator () (const std::vector<typename Funct::ValueType>& vec){
        std::vector<typename Funct::ValueType> retVec;
        Funct f;
        for (int i=0; i<vec.size(); i++){
            retVec.push_back(f(vec.at(i)));
        }
        return retVec;
    }
};

int main() {
    int n = 3;
    Repeat<std::string,4> rep;
    Repeat<int,5> repint;
    std::cout<<rep("foo")<<std::endl;
    std::cout<<repint(7);
    Mapper< Repeat<std::string,4> > mapper;
    std::vector<std::string> vec_str;
    vec_str.push_back("foo"); vec_str.push_back("bar");
    std::vector<std::string> testvec = mapper(vec_str);
    return 0;
}
