//yaeldorani@gmail.com

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Node.hpp"


class Queue{

private:
    static int ID; // ID to the graph

public:
 
    Node** queue; // the actuall queue
    int size; // the queue's size
    int id; // id to identify the queue
    int next; // the last palce that full in the queue
    
    Queue(int n); 
    ~Queue();

    void enqueue(Node* node); // add a new node to the queue
    Node* dequeue(); // delete the first node
    bool contains(Node* node);
    Node* deleteNotInOrder(int id);
};


#endif
