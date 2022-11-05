//
// Created by joonhyeok on 10/24/22.
//

#ifndef SYSTEM_SW3_LINKED_LIST_H
#define SYSTEM_SW3_LINKED_LIST_H

#endif //SYSTEM_SW3_LINKED_LIST_H

#include <iostream>
#include <stdlib.h>  // abort() - header
#include <cassert>   // header for assert


/// Linked List class definition
class DLinkedList {
private:
    // Inner class
    class node {
    public:
        unsigned int data;
        node* prev_node;
        node* next_node;

        node(unsigned int data_in, node* prev_node_in, node* next_node_in) :
                data(data_in), prev_node(prev_node_in), next_node(next_node_in){
        }
        ~node(){
            std::cout << "!! Node delete !!" << std::endl;
        }
    };

    node* head;  // head of the list
    node* tail;  // tail of the list

    unsigned int size;      // current size of the list
    unsigned int max_size;  // max_size of the linked list


public:
    DLinkedList(unsigned int max_size_in);  // Constructor

    ~DLinkedList();  // Destructor

    // return head
    node* get_head() const{
        return head;
    }

    // return tail
    node* get_tail() const {
        return tail;
    }

    // add Node
    void addNode(int data_i);

    // erase node which have specific data
    void eraseNode(unsigned int data_i);

    // find node which have specific data, return true when find the node and increase hit count
    bool findNode(node* node_find, unsigned int data_i);

    // print linked list
    void print();
};
