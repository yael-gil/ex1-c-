//yaeldorani@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Node.hpp"


namespace graph{


class Graph{

private:
    static int ID; // ID to the graph

public:
 
    int* weight; // array for the edge's weight
    Node** graph; // array to store the graph's nodes
    int size; // the graph's size
    int id;   

    Graph(int n); 
    ~Graph();
    void addEdge(int src, int dst, int weight = 1);
    void removeEdge(int src, int dst);
    void printGraph();
    Node* findNodeInGraph(int id);
};
}

#endif