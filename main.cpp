#include <iostream>
#include "LinkedList.h"

int main(void){

    LinkedList<int> list;
    std::cout<< list.empty()<<std::endl;
    list.push_back(21);
    list.push_front(22);
    list.push_back(21);
    list.push_back(22);
    list.push_back(23);
    list.print();
    std::cout<<std::endl;
    list.del_index(5); 
    list.print();
    std::cout<< list.empty()<<std::endl;
    std::cout<< list.size()<<std::endl;

    return 0;
}