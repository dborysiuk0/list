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
    Node<T> *head=nullptr;   
    explicit LinkedList(T data){
        head -> value = data;      
    }
    bool empty();
    void push_front(T data);
    void push_back(T data);
    int size();
    void del_index(int index);
    void print();
};
