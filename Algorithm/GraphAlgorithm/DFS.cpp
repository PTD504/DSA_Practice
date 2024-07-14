// Depth-First Search (DFS) is a fundamental algorithm for traversing graph (or tree) data structures. 
// The algorithm starts at the root node (selecting some arbitrary node as the root in the case of a graph)
// and explores as far as possible along each branch before backtracking.
// The code below is the implementation of DFS algorithm on an undirected unweighted graph 

#include <iostream>
#include "AdjacencyList.h"

template <typename T>
void DFS(UndirectedGraph<T> adj, UnorderedMap<T, int>& isVisited, T vertex) {
	std::cout << vertex << ' ';

	for (auto v : adj.retrieveData(vertex)) {
		if (isVisited.search(v)) continue;
		isVisited[vertex] = 1;
		DFS(adj, isVisited, v);
	}
}

int main() {
	UndirectedGraph<char> adj;
	adj.addVertex('a');
	adj.addVertex('B');
	adj.addVertex('Z');
	adj.addVertex('m');

	adj.addEdge('m', 'a');
	adj.addEdge('m', 'B');
	adj.addEdge('Z', 'a');
	adj.addEdge('a', 'b');

	UnorderedMap<char, int> mp;
	mp['m'] = 1;

	DFS(adj, mp, 'm');
}