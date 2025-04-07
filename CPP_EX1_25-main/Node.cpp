//yaeldorani@gmail.com

#include "Node.hpp"

    Node::Node(int n){
            edg = new Node*[n-1]; // create a new array 
            weight = new int[n-1]; // create a new array
            id = ID ++; // define the id of the new node
            edgeAmount = 0; 
            size = n;
    }
    Node::~Node(){
        delete[] edg;
        delete[] weight;
    }
    void Node:: addWeigh(int weight){
        this->weight[edgeAmount] = weight;
    }
    void Node::addNewEdge(Node* node){
        // add exepration
        if(edgeAmount == size-1){ // c'ant add new Node 
            return;
        }
        this->edg[edgeAmount] = node;
        this->edgeAmount++;
    }

int Node::ID = 1;