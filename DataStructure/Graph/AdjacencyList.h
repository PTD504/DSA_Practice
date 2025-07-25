// A graph data structure consists of a set of nodes (vertices) and a set of edges connecting these nodes.

#include "../UnorderedMap/UnorderedMap.h"
#include <vector>

template <typename T>
class Graph {
protected:
    UnorderedMap<T, std::vector<T> > adjList; // adjacency list

public:
    Graph() {}

    virtual void addEdge(T v, T w) = 0;

    void addVertex(T v) {
        if (adjList.search(v)) return;
        adjList[v] = {};
    }

    // Function to display the graph
    void displayGraph() {
        for (auto &entry : adjList) {
            std::cout << entry.first << ":";
            for (T &w : entry.second) {
                std::cout << " -> " << w;
            }
            std::cout << '\n';
        }
    }

    // Function to get all the adjacency vertices of the vertex 'vertex'
    std::vector<T> retrieveData(T vertex) {
        return adjList[vertex];
    }
};

template <typename T>
class UndirectedGraph: public Graph<T>
{
public:
    
    UndirectedGraph() {}

    void addEdge(T v, T w) override {
        Graph<T>::adjList[v].push_back(w);
        Graph<T>::adjList[w].push_back(v);
    }
};

template <typename T>
class DirectedGraph: public Graph<T>
{
public:
    
    DirectedGraph() {}

    void addEdge(T v, T w) override {
        Graph<T>::adjList[v].push_back(w);
    }
};
