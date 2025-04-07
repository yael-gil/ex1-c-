//yaeldorani@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

class Node{

    //private:
    static int ID;
public:
    Node** edg; // array for the edge 
    int* weight; // array for the edge's weight
    int id; // id to identify each node
    int edgeAmount; // how much child's there ara right now
    int size; // save the current graph size
  //  int* shortestPath; // array to store the length of the shortest path (form given node)
    
    Node(int n); 
    ~Node();
    void addWeigh(int weight); // add weigh to a new edge
    void addNewEdge(Node* node); // add a new edge 
};


#endif
