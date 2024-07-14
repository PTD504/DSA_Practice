// Prim's algorithm is a classic algorithm in computer science used to find the minimum spanning tree (MST)
// of a weighted, undirected graph. 
// The minimum spanning tree of a graph is a subset of the edges that connects all vertices 
// in the graph without any cycles and with the minimum possible total edge weight.

#include <iostream>
#include "Heap.h"
#include "WeightedGraph.h"

template <typename T>
struct specialNode
{
	T vertex;
	int cost;

	bool operator<(const specialNode& other) {
		return cost < other.cost;
	}

	bool operator>(const specialNode& other) {
		return cost > other.cost;
	}
};

template <typename T>
void PrimsAlgorithm(UndirectedGraph<T> adj, T source) {
	UnorderedMap<T, int> cost;
	UnorderedMap<T, T> parent;
	UnorderedMap<T, int> inMST;
	MinHeap<specialNode<T> > priorq;

	cost[source] = 0;
	parent[source] = source;
	priorq.insert({source, 0});

	while (!priorq.isEmpty()) {
		auto vertex = priorq.top().vertex;
		auto ct = priorq.top().cost;
		priorq.pop();

		if (inMST.search(vertex)) continue;
		inMST[vertex] = 1;

		for (auto vt : adj.retrieveData(vertex)) {
			auto v = vt.first;
			auto ct1 = vt.second;

			if (inMST.search(v) == false) {
				if (cost.search(v) == false) {
					cost[v] = ct1;
					parent[v] = vertex;
					priorq.insert({v, ct1});
				}
				else if (cost[v] > ct1) {
					cost[v] = ct1;
					parent[v] = vertex;
					priorq.insert({v, ct1});
				}
			}
		}
	}

	for (auto v : parent) {
		if (v.second == v.first) continue;
		std::cout << v.second << '-' << v.first << '\t' << cost[v.first] << '\n';
	}
}

int main() {
	UndirectedGraph<std::string> adj;
	adj.addVertex("vertex1");
	adj.addVertex("vertex2");
	adj.addVertex("vertex3");
	adj.addVertex("vertex4");
	adj.addVertex("vertex5");

	adj.addEdge("vertex1", "vertex2", 12);
	adj.addEdge("vertex3", "vertex2", 20);
	adj.addEdge("vertex4", "vertex1", 24);
	adj.addEdge("vertex2", "vertex4", 18);
	adj.addEdge("vertex3", "vertex5", 21);
	adj.addEdge("vertex1", "vertex5", 10);

	std::string source = "vertex3";

	PrimsAlgorithm(adj, source);
}