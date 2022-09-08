#include <iostream>
#include "LinkedList.h"

    // Check if the list is empty
    template<typename T>
    bool LinkedList<T>::empty(){
        if(head == 0){
            return true;  
        }
        else{
            return false;
        }
    }
    template<typename T>
    void LinkedList<T>::push_front(T data){
        Node<T> *new_var = new Node<T>; 
        new_var -> value = data;
        new_var -> next = head;
        head = new_var;
    }
    template<typename T>
    void LinkedList<T>::push_back(T data){
        if(!empty()){
        Node<T> *new_var = head;
        while( new_var != 0 && new_var -> next != 0 ){
            new_var = new_var -> next;
        }       
        if(new_var){
            new_var -> next = new Node<T>;
            new_var -> next -> value = data;
        }      
        } 
        else{
            push_front(data);
            return;
        }
    }

    // We count how many Node elements are in the list
    template<typename T>
    int LinkedList<T>::size(){
        int amount=0;
        Node<T> *new_var = head;
        while( new_var != 0 ){
            new_var = new_var -> next;
            amount++;
        }
        delete new_var;
        return amount;
    }
    // We check which element we are deleting, if it is the first one, then it is necessary to move the head. 
    // We check the correctness of the index.
    template<typename T>
    void LinkedList<T>::del_index(int index){
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
    // Output of each element to the std::cout stream
    template<typename T>
    void LinkedList<T>::print(){
        Node<T> *new_var = head;
        while( new_var != 0 ){
            std::cout << new_var -> value << std::endl;
            new_var = new_var -> next;
        }
        delete new_var;
    }