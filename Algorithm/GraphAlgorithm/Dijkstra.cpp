// Dijkstra's Algorithm is designed to find the shortest path from a starting node 
// to all other nodes in a weighted graph with non-negative edge weights. 
// The key idea is to iteratively expand the shortest known path from the starting node, 
// always choosing the next node with the smallest tentative distance.

#include <iostream>
#include <vector>
#include "WeightedGraph.h"
#include "Heap.h"

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
UnorderedMap<T, int> DijkstraAlgorithm(UndirectedGraph<T> adj, T source) {
	MinHeap<specialNode<T> > priorq;
	UnorderedMap<T, int> cost;
	cost[source] = 0;
	priorq.insert({source, 0});

	while (!priorq.isEmpty()) {
		auto v = priorq.top().vertex;
		auto ct = priorq.top().cost;
		priorq.pop();

		for (auto vt : adj.retrieveData(v)) {
			if (cost.search(vt.first) == false) {
				cost[vt.first] = ct + vt.second;
				priorq.insert({vt.first, cost[vt.first]});
			}
			else if (cost[vt.first] > ct + vt.second) {
				cost[vt.first] = ct + vt.second;
				priorq.insert({vt.first, cost[vt.first]});
			}
		}
	}

	return cost;
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

	std::string source = "vertex3";

	auto shortestPath = DijkstraAlgorithm(adj, source);

	for (auto v : shortestPath) {
		std::cout << v.first << ' ' << v.second << '\n';
	}
}