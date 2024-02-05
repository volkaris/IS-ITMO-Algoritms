#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TupleComparator {
	bool operator()(const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) const {
		return std::get<2>(a) > std::get<2>(b);
	}
};


void add_edge(int current_vertex, vector<vector<pair<int, int>>>& graph, vector<bool>& visited,
              std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, TupleComparator>&
              priority_queue) {
	visited[current_vertex] = true;
	for (const auto& edges : graph[current_vertex]) {
		if (!visited[edges.first]) {
			priority_queue.push({current_vertex, edges.first, edges.second});
		}
	}
}


int Prim(int start_vertice = 1) {
	int V, E;
	cin >> V >> E;
	int cost_Of_mst = 0;
	int amount_of_iter = 0;
	std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, TupleComparator> edges;
	vector<vector<pair<int, int>>> graph(V + 1);
	std::vector<std::tuple<int, int, int>> MST(V - 1);
	
	vector<bool> visited(V + 1, false);

	MST.reserve(V - 1); 
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);
	}

	add_edge(start_vertice, graph, visited, edges);

	int edges_in_mst = 0;

	while (edges_in_mst != V - 1) {
	
		++amount_of_iter;
		const int end = std::get<1>(edges.top());

		if (visited[end]) {
			edges.pop();
			continue;
		}


		MST[edges_in_mst++] = edges.top();

		cost_Of_mst += std::get<2>(edges.top());
		edges.pop();
		add_edge(end, graph, visited, edges);
	}

	
	return cost_Of_mst;
}


int main() {
	cout << Prim();
}
