#include <iostream>
#include "Graph.h"

int main() {
    Graph graph(10,0,"UNDIRECTED");
    graph.addEdge(1,8);
    graph.addEdge(1,5);
    graph.addEdge(1,2);
    graph.addEdge(2,9);
    graph.addEdge(8,6);
    graph.addEdge(8,4);
    graph.addEdge(8,3);
    graph.addEdge(6,10);
    graph.addEdge(6,7);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
