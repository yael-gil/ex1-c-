//yaeldorani@gmail.com

#include "Graph.hpp"
#include <iostream>

namespace graph{
    
    int Graph::ID = 0;

        Graph:: Graph(int n){
            size = n;
            id = ID++;

            graph = new Node* [n];
            for (int i = 0; i < n; i++){            
                graph[i] = new Node(n);
            }
        }
        Graph::~Graph() {
            for (int i = 0; i < size; i++) {
                delete graph[i];  // 
            }
            delete[] graph;  //
        }

      /*  Graph Graph:: deepCopy() {
            Graph newGraph (this->size);
            newGraph.size = this->size;
            newGraph.id = this->id;
            newGraph.graph = this->graph;

            return newGraph;
        }
*/
    Node* Graph:: findNodeInGraph(int id){
        for (int i = 0; i < this->size; i++){
            if(this->graph[i]->id == id){
                return this->graph[i];
            }
        }
        return nullptr;
    }

        void Graph:: addEdge(int src, int dst, int weight){
            if (src == dst){ // if the src == dst d'ont do anything
                return;
            }
            Node* current;
            Node* address_src = nullptr;
            Node* address_dst = nullptr;
            for (int i = 0; i < this->size; i++){ //find the src and dst in the graph, and put them in the Node's array
                current = this-> graph[i];
                if(current->id == src) {
                    address_src = current;
                } if(current->id == dst) {
                    address_dst = current;
                }
            } if (address_dst == nullptr || address_src == nullptr){ // if dst or src null return
                return;
            }else{ 
                for(int j = 0;j < address_src->edgeAmount; j++){
                    if (address_src->edg[j]->id == address_dst->id){
                        return;
                    }
                }
                address_dst->addNewEdge(address_src); // add new edje
                address_dst->addWeigh(weight); // add the edje's weight 
                address_src->addNewEdge(address_dst); // add new edje
                address_src->addWeigh(weight); // add the edje's weight 

        }
    }

    void Graph:: removeEdge(int src, int dst){
        if (src == dst){ // if the src == dst d'ont do anything
            return;
        }
        Node* current;
        Node* address_src = nullptr;
        Node* address_dst = nullptr;
        for (int i = 0; i < this->size; i++){ //find the src and dst in the graph, and put them in the Node's array
            current = this-> graph[i];
            if(current->id == src) {
                address_src = current;
            } if(current->id == dst) {
                address_dst = current;
            }
            // return exreption
        } if (address_dst == nullptr || address_src == nullptr){ // if dst or src null return
            return;
        }else{ 
            for (int k = 0; k <=address_dst->edgeAmount; k++){
                if (address_dst->edg[k]->id == address_src->id){
                    for(int j = k; j <= address_dst->edgeAmount; j++){
                        address_dst->edg[j] = address_dst->edg[j+1]; // remove the src from the edg array
                        address_dst->weight[j] = address_dst->weight[j+1];
                    } 
                    address_dst->edg[address_dst->edgeAmount] = nullptr;// resate the last inde
                    address_dst->weight[address_dst->edgeAmount] = -1;// resate the last index

                    address_dst->edgeAmount--;
                }
            }
            for (int k = 0; k <=address_src->edgeAmount; k++){
                if (address_src->edg[k]->id == address_dst->id){
                    for(int j = k; j <= address_src->edgeAmount; j++){
                    
                        address_src->edg[j] = address_src->edg[j+1]; // remove the dst from the edg array
                        address_src->weight[j] = address_src->weight[j+1];

                    }                   
                  
                    address_src->edg[address_src->edgeAmount] = nullptr; // resate the last index
                    address_src->weight[address_src->edgeAmount] = -1;// resate the last index
                    address_src->edgeAmount--;
                   
                }
            }
        }
    }
 /*  void Graph:: printGraph(){

        Graph newGraph = this->deepCopy();
        
        // int** EdgeList = new int*[this->size];   
        //for (int k = 0; k < this->size; k++){ // list to store the printed edge
        //      EdgeList[k] = new int[2];
        // }      
        int currentInList = 0;
        int idNextNode = -1;
        int idCurNode = -1;

        for (int i = 0; i < this->size; i++){
            Node* curNode = newGraph.graph[i];
            idCurNode = curNode->id; //take the id to remove from newGraph
            
            //print "curNOde id ->"
            
            Node* next = curNode->edg[0];
            if(next->edgeAmount != 0){
        
            idNextNode = next->id; //take the id to remove from newGraph
            
            //print "nextNode id ->"
            
                newGraph.removeEdge(idCurNode,idNextNode);
                newGraph.printGraph();
        //    EdgeList [currentInList] = arr; // insert the arr into the list
        //    currentInList++;
        //    EdgeList [currentInList] = arr2; // insert the arr into the list
        //    currentInList++;
            }
        }
        for (int k = 0; k < this->size; k++){
            delete[] EdgeList[k];
        } 
        delete[] EdgeList;
    }
*/

/*
print the graph. 
save the id and print the edge when the left edge's id smaller than the right edge's id.
*/
    void Graph:: printGraph(){
        int currentID = -1; //save the current Node id
        int childID = -1; // save the current child Node id
        for(int i = 0; i < this->size; i++){
            currentID = this->graph[i]->id;
          //  std::cout<< "start print: "<< graph[i]->id<<std::endl;
            for (int j = 0; j < this->graph[i]->edgeAmount; j++){
                childID = this->graph[i]->edg[j]->id;
                if (childID > currentID){
                   std::cout<<currentID<<"->"<<childID<<std::endl;
                }
            }                    
        }

    }
}
