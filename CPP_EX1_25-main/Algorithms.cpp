//yaeldorani@gmail.com

#include "Algorithms.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>


using namespace graph;

Graph Algorithms:: bfs(Graph* graphA, Node* root){
    Graph tree(graphA->size);

    for (int j = 0; j < graphA->size; j++){
        if(graphA->graph[j] == root){
    
            for(int k = 0; k < graphA->size; k++){ // adapt the graph's id to the tree
                tree.graph[k]->id = graphA->graph[k]->id;
            } 

            Queue gray(graphA->size); // mark the visited Node
            Queue black(graphA->size); // mark the Node we finished


            gray.enqueue(root); // add the root

            while(gray.next != 0){ // continue as long as there are Node that we visited and not finished
                Node* deq = gray.dequeue();
                black.enqueue(deq); // mark the current visited node as finished
                
             
                //mark the child edges that as visited and add the edge to the tree 
                for (int i = 0; i < deq->edgeAmount; i++){ // 
                    if (!black.contains(deq->edg[i]) && !gray.contains(deq->edg[i])) { // if the Node not marked
                    //    std::cout<<"add edge"<<deq->id<<"->"<<deq->edg[i]->id<<std::endl;
                        gray.enqueue(deq->edg[i]); // mark
                        tree.addEdge(deq->id, deq->edg[i]->id, deq->weight[i]); //add new edge       
                    }
                }
            } //std::cout<<"end bfs \n";
            return tree;
        }
    }
    return tree; // expration
    
    //add delete?

}
Graph Algorithms::dfs(Graph* graphA, Node* root) {
    Graph tree(graphA->size);

    std::cout<<"get in dfs"<<std::endl;
    for (int i = 0; i < graphA->size; i++) {
        if (graphA->graph[i] == root) {

            for (int k = 0; k < graphA->size; k++) { 
                tree.graph[k]->id = graphA->graph[k]->id;
            }

            Stack stack(graphA->size);
            Queue visited(graphA->size);

            stack.push(root);

            while (stack.next != 0) {
                Node* cur = stack.pop();
                visited.enqueue(cur);

                for (int j = 0; j < cur->edgeAmount; j++) {
                    if (!visited.contains(cur->edg[j]) && !stack.contains(cur->edg[j])) {
                        stack.push(cur->edg[j]);
                        tree.addEdge(cur->id, cur->edg[j]->id, cur->weight[j]);
                    }
                }
            }
            return tree;
        }
    }
    return tree;
}

Graph Algorithms::dijkstra(Graph* graphA, Node* root) {
    std::cout << "get in dij \n";

    Graph tree(graphA->size);

    //initalizes the id's of the Node in the tree
    for (int k = 0; k < graphA->size; k++) {
        tree.graph[k]->id = graphA->graph[k]->id;
    }

    
    int* distance = new int[graphA->size]; //keep the distance between root to node
    int* par = new int[graphA->size]; // keep the parent of the nodes to restore the tree's edges
    bool* visited = new bool[graphA->size](); // mark visited nodes

    //reset distance as infinty, par as -1 and visited as false
    for (int n = 0; n < graphA->size; n++) {
        distance[n] = std::numeric_limits<int>::max();
        par[n] = -1;
        visited[n] = {false};
    }

    distance[root->id - 1] = 0; // root is in distance 0 from himself


    for (int i = 0; i < graphA->size; i++) {

        int minDist = std::numeric_limits<int>::max();
        int curIdx = -1;
        
        //check if there is shorter distance
        for (int j = 0; j < graphA->size; j++) {
            if (!visited[j] && distance[j] < minDist) {
                minDist = distance[j];
                curIdx = j;
            }
        }

        if (curIdx == -1) break; // finished check all the node

        Node* cur = graphA->graph[curIdx];
        visited[curIdx] = true;


        for (int j = 0; j < cur->edgeAmount; j++) {
            Node* neighbor = cur->edg[j];
            int weight = cur->weight[j];

            //dijkstra work only in non-negative weight
            if (weight < 0) {
                throw std::runtime_error("Cannot perform Dijkstra on a graph with negative weights.");
            }

            int neighborIdx = neighbor->id - 1; // id start with 1 
            if (distance[neighborIdx] > distance[curIdx] + weight) {
                distance[neighborIdx] = distance[curIdx] + weight;
                par[neighborIdx] = curIdx; // save the parent in the shortest path
            }
            
        }
    }

    //build te the tree by par
    for (int m = 0; m < graphA->size; m++) {
        if (par[m] != -1) {
            tree.addEdge(par[m] + 1, m + 1, distance[m]); 
        }
    }

    //delete from the memory
    delete[] visited;
    delete[] distance;
    delete[] par;

    return tree;
}

Graph Algorithms::prim(Graph* graphA) {
    std::cout << "Starting Prim's Algorithm\n";

    Graph tree(graphA->size);
    
    for (int k = 0; k < graphA->size; k++) {
        if (!graphA->graph[k] || !tree.graph[k]) {
            throw std::runtime_error("Error: Null node pointer found during tree initialization.");
        }
        tree.graph[k]->id = graphA->graph[k]->id;
    }

    Queue visited(graphA->size);
    Queue notVisited(graphA->size);

    bool* visitedB = new bool[graphA->size](); 

    for (int j = 1; j < graphA->size; j++){
         notVisited.enqueue(graphA->graph[j]);
    }

    visited.enqueue(graphA->graph[0]);
    visitedB[ graphA->graph[0]->id ] = true;
    
    Node* next1 = nullptr;
    Node* next2 = nullptr;
    int currentMin = std::numeric_limits<int>::max();

    while(notVisited.next != 0) {
        currentMin = std::numeric_limits<int>::max();
        next1 = nullptr;
        next2 = nullptr;
        
        for (int i = 0; i < visited.next; i++){
            Node* cur = visited.queue[i];
            for (int k = 0; k < cur->edgeAmount; k++){
                Node* neighbor = cur->edg[k];
                if (!visitedB[ neighbor->id ]) {
                    if (cur->weight[k] < currentMin) {
                        currentMin = cur->weight[k];
                        next2 = cur;
                        next1 = neighbor;
                    }
                }
            }
        }
        if (!next1 || !next2) {
            std::cout << "No valid edge found, terminating loop.\n";
            break;
        }
        
        tree.addEdge(next2->id, next1->id, currentMin);
        std::cout << "Added edge: " << next2->id << " -> " << next1->id 
                  << " (Weight: " << currentMin << ")\n";
        
        visited.enqueue(next1);
        visitedB[next1->id] = true;
        notVisited.deleteNotInOrder(next1->id); 
    }
    
    delete[] visitedB;
    return tree;
}



