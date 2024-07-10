#include <iostream>
#include "Graph.h"

int main() {
    UndirectedGraph<int> g;
    g.addVertex(12);
    g.addVertex(19);
    g.addVertex(100);
    
    g.addEdge(12, 19);
    g.addEdge(100, 12);
    
    g.displayGraph();
    
}