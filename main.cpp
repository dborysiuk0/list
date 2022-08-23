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
    Node<T> *head;
    LinkedList(){
        head = 0;
    }
    LinkedList(T data){
        head -> value = data;
        head -> next = new Node<T>;
       
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
        else{
           head -> next = new Node<T>;
           head -> value = data;
        }
        
    }
    void print(){
        Node<T> *new_var = head;
        while( new_var != 0 && new_var -> next != 0 ){
            std::cout << new_var -> value << std::endl;
            new_var = new_var -> next;
        }
    }
};

int main(void){

    LinkedList<int> list(10);
    list.push_back(20);
    list.push_back(21);
    list.push_back(21);
    list.print();
    return 0;
}