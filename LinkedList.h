#pragma once

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
    Node<T> *head = nullptr;
    // To add an element to an empty list, you need to use a function push_front
    LinkedList() = default;
    // We redefine the constructor to accept the argument
    LinkedList(T data) 
    :head(new Node<T>)
    {
        head -> value = data;      
    }
        // Check if the list is empty
    bool empty(){
        if(head != 0){
          return true;  
        }
        else{
            return false;
        }
    }
    void push_front(T data){
        Node<T> *new_var = new Node<T>; 
        new_var -> value = data;
        new_var -> next = head;
        head = new_var;
    }
    void push_back(T data){
        if(empty()){
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
    int size() const
    {
        int amount=0;
        Node<T> *new_var = head;
        while( new_var != 0 ){
            new_var = new_var -> next;
            amount++;
        }
        return amount;
    }
    // We check which element we are deleting, if it is the first one, then it is necessary to move the head. 
    // We check the correctness of the index.
    void del_index(int index){
        if(index == 0){
            Node<T> *new_head = head ->next;
            delete head;
            head = new_head;
        }
        else if(index > size()-1){
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
    void print() const
    {
        Node<T> *new_var = head;
        while( new_var != 0 ){
            std::cout << new_var -> value << std::endl;
            new_var = new_var -> next;
        }
        delete new_var;
    }
};

