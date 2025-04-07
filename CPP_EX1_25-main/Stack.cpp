//yaeldorani@gmail.com

#include "Stack.hpp"

Stack:: Stack(int n){
    id = ID++;
    size = n;
    stack = new Node*[n]; // create a new array 
    next = 0;

} 
Stack:: ~Stack(){
    delete[] stack;
}

void Stack:: push(Node* node){ // add a new node to the stack
    this->stack[this->next] = node;
    this->next++;
}

Node* Stack:: pop(){ // delete the last place in the array 
    
    Node* returnNode = this->stack[next-1];
    this->stack[next - 1] = nullptr;
    this->next--;

    return returnNode;
}

bool Stack:: contains(Node* node){
    for (int i = 0; i < this->next; i++){
        if (node == this->stack[i]){
            return true;
        }
    } return false;
}


int Stack::ID = 0;
