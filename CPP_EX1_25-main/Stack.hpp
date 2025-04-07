//yaeldorani@gmail.com

#ifndef STACK_HPP
#define STACK_HPP
#include "Node.hpp"


class Stack{

private:
    static int ID; // ID to the graph

public:
 
    Node** stack; // the actuall stack
    int size; // the stack's size
    int id; // id to identify the stack
    int next; // the last palce that full in the stack
    
    Stack(int n); 
    ~Stack();

    void push(Node* node); // add a new node to the stack
    Node* pop(); // delete the last node
    bool contains(Node* node);
};


#endif
