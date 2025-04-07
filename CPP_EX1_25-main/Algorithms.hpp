//yaeldorani@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace graph;


class Algorithms{

    private:

public:
 

    Algorithms(); 
    ~Algorithms();

    static Graph bfs(Graph* graph, Node* root);
    static Graph dfs(Graph* graph, Node* root);
    static Graph dijkstra(Graph* graph, Node* root);
    static Graph prim(Graph* graph);

};


#endif