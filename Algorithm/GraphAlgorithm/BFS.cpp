// Breadth-First Search (BFS) is a fundamental graph traversal algorithm used to explore nodes and edges of a graph. 
// The main idea of the Breadth-First Search (BFS) algorithm is to explore the nodes of a graph level by level, starting from a given source node.
// // The code below is the implementation of DFS algorithm on an undirected unweighted graph 

#include <iostream>
#include "AdjacencyList.h"
#include "Queue.h"

template <typename T>
void BFS(UndirectedGraph<T> adj, UnorderedMap<T, int>& isVisited, T vertex) {
	Queue<T> q;
	q.push(vertex);

	while (!q.isEmpty()) {
		int sz = q.size();

		while (sz--) {
			auto v = q.front();
			q.pop();

			std::cout << v << ' ';

			for (auto vt : adj.retrieveData(v)) {
				if (isVisited.search(vt)) continue;
				isVisited[vt] = 1;
				q.push(vt);
			}
		}
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

	BFS(adj, mp, 'm');
}