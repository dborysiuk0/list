#include <iostream>

template<typename T>
class Node{
public:
    T value;
    Node *next;
};
template<typename T>
class LinkedList{
public:
    Node<T> *head = new Node<T>;
    LinkedList(){
        head = 0;
    }
    LinkedList(T data){
        head -> value = data;      
    }
    void push_back(T data){
        Node<T> *new_var = head;
        while( new_var != 0 && new_var -> next != 0 ){
            new_var = new_var -> next;
        }       
        if(new_var){
            new_var -> next = new Node<T>;
            new_var -> next -> value = data;
        }       
    }
    void push_front(T data){
        Node<T> *new_var = new Node<T>; 
        new_var -> value = data;
        new_var -> next = head;
        head = new_var;
    }
    int size(){
        int amount=0;
        Node<T> *new_var = head;
        while( new_var != 0 ){
            new_var = new_var -> next;
            amount++;
        }
        delete new_var;
        return amount;
    }
    void del_index(int index){
        if(index == 0){
            Node<T> *new_head = head ->next;
            delete head;
            head = new_head;
        }
        else if(index == size()){
            Node<T> *ptr = head;
            int i=0;
            while ((i+1) != index)
            {
                ptr = ptr -> next;
            }
            delete ptr -> next;
        }
        else if(index > size()){
            std::cout<<"This index does not exist in the list"<<std::endl;
            return;
        }
        else{
            Node<T> *ptr = head;
            Node<T> *p;
            int i=0;
            while ((i+1) != index)
            {
                ptr = ptr -> next;
                i++;
            }
            p = ptr -> next;
            ptr ->next = ptr -> next -> next;
            delete p;
        }    
    }
    bool empty(){
        if(head != 0){
          return true;  
        }
        else{
            return false;
        }
    }

    void print(){
        Node<T> *new_var = head;
        while( new_var != 0 ){
            std::cout << new_var -> value << std::endl;
            new_var = new_var -> next;
        }
        delete new_var;
    }
};

int main(void){

    LinkedList<int> list;
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