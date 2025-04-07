//yaeldorani@gmail.com

#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>
using namespace graph;

/*לא יודעת למה, אבל כל בדיקה של גרף בנפרד עובדת כראוי, כאשר מחברים את כל הבדיקות ביחד,
 הוא מדפיס  רק את  הגרף הראשון*/
int main(){
    std::cout << "Starting program...\n";
    Graph graph(5);
    graph.addEdge(1,2,4);
    graph.addEdge(2,3,3);
    graph.addEdge(1,2,5);
    graph.addEdge(2,1,5);
  //  graph.addEdge(1,2,5);
    graph.printGraph();
    graph.removeEdge(2,3);
    graph.printGraph();
   // graph.removeEdge(2,1);
   // graph.printGraph();

    Graph bfsGraph(6);
    bfsGraph.addEdge(1,3);
    bfsGraph.addEdge(1,4);
    bfsGraph.addEdge(3,2);
    bfsGraph.addEdge(4,2);
    bfsGraph.addEdge(5,2);
    bfsGraph.addEdge(5,6);
    Graph tree = Algorithms:: bfs(&bfsGraph, bfsGraph.graph[0]);
    tree.printGraph();

    Graph dfsGraph(6);
    dfsGraph.addEdge(1,3);
    dfsGraph.addEdge(1,4);
    dfsGraph.addEdge(3,2);
    dfsGraph.addEdge(4,2);
    dfsGraph.addEdge(5,2);
    dfsGraph.addEdge(5,6);

    Graph treeDfs = Algorithms:: dfs(&dfsGraph, dfsGraph.graph[0]);
    treeDfs.printGraph();

    Graph dijkGraph(6);
    std::cout<<"add new tree \n";
    dijkGraph.addEdge(1,3);
    dijkGraph.addEdge(1,4);
    dijkGraph.addEdge(3,2);
    dijkGraph.addEdge(4,2);
    dijkGraph.addEdge(5,2);
    dijkGraph.addEdge(5,6);

   
  
    Graph treeDijk = Algorithms:: dijkstra(&dijkGraph, dijkGraph.graph[0]);
    treeDijk.printGraph();

  Graph primGraph(6);
      std::cout<<"add new tree \n";
      primGraph.addEdge(1,3);
      primGraph.addEdge(1,4);
      primGraph.addEdge(3,2);
      primGraph.addEdge(4,2);
      primGraph.addEdge(5,2);
      primGraph.addEdge(5,6);    
    
      Graph treePrim = Algorithms:: prim(&primGraph);
      treePrim.printGraph();
    std::cout << "Stoping program...\n";

}
