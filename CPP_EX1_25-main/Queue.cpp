//yaeldorani@gmail.com

#include "Queue.hpp"

Queue:: Queue(int n){
    id = ID++;
    size = n;
    queue = new Node*[n]; // create a new array 
    next = 0;

} 
Queue:: ~Queue(){
    delete[] queue;
}

void Queue:: enqueue(Node* node){ // add a new node to the queue
    this->queue[this->next] = node;
    this->next++;
}

Node* Queue:: dequeue(){ // delete the first place in the array 
    
    Node* returnNode = this->queue[0];

    for(int i = 0; i < next - 1; i++){ // 
        this->queue[i] = this->queue[i+1];
    }
    this->queue[next - 1] = nullptr;
    this->next--;

    return returnNode;
}
Node* Queue::deleteNotInOrder(int id){
    Node* returnNode = nullptr; 
    for (int i = 0; i < this->size; i++){
        if (this->queue[i]->id == id){
            returnNode = this->queue[i];
            for (int j = i; j<this->size -1; j++){
                this->queue[j] = this->queue[j+1];
            }
            this->queue[this->size -1] = nullptr;
            this->next--;
            return returnNode;
        }
    } return returnNode;
}

bool Queue:: contains(Node* node){
    for (int i = 0; i < this->next; i++){
        if (node == this->queue[i]){
            return true;
        }
    } return false;
}


int Queue::ID = 0;
