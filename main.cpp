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
        //head = 0;
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
    void del_index(int index){
        if(index == 0){
            Node<T> *new_head = head ->next;
            delete head;
            head = new_head;
        }
        else{
            Node<T> *ptr = head;
            Node<T> *p;
            int i=0;
            while ((i+1) != index)
            {
                ptr = ptr -> next;
            }
            p = ptr -> next;
            ptr ->next = ptr -> next -> next;
            delete p;
        }    
    }

    void print(){
        Node<T> *new_var = head;
        while( new_var != 0 ){
            std::cout << new_var -> value << std::endl;
            new_var = new_var -> next;
        }
    }
};

int main(void){

    LinkedList<int> list(10);
    list.push_back(20);
    list.push_back(21);
    list.push_front(22);
    list.push_back(21);
    list.print();
    std::cout<<std::endl;
    list.del_index(1);
    list.print();
    std::cout<<std::endl;
    list.push_back(0);
    list.print();

    return 0;
}