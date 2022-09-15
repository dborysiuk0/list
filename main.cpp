#include <iostream>
#include "LinkedList.h"

int main(void){

    LinkedList<int> list;
    //std::cout<< list.empty()<<std::endl;
    list.push_back(21);
    list.push_front(22);
    list.print();
    std::cout<<std::endl;
    std::cout<< list.size()<<std::endl;
     std::cout<<std::endl;
    list.del_index(2); 
    list.print();
    return 0;
}