#include <iostream>
#include <vector>
#include <cstring>
#include <ranges>

using namespace std;


int64_t start_vertex = 1, end_vertex;
vector<vector<int64_t>> graph;


vector<bool> visited;


int64_t dfs(int64_t current_vertex, int64_t mincap, vector<vector<int64_t>>& capacity, vector<vector<int64_t>>& f) {
	if (current_vertex == end_vertex) {
		return mincap;
	}

	visited[current_vertex] = true;

	for (const auto& children : graph[current_vertex]) {
		auto flow_capacity = capacity[current_vertex][children] - f[current_vertex][children];
		if (!visited[children] and flow_capacity > 0) {
			int64_t flow = dfs(children, min(mincap, flow_capacity),
			                   capacity, f);
			if (flow > 0) {
				f[current_vertex][children] += flow;
				f[children][current_vertex] -= flow;
				return flow;
			}
		}
	}
	return 0;
}


int64_t ford_fulkerson(vector<vector<int64_t>>& capacity, vector<vector<int64_t>>& f) {
	int64_t maxflow = 0;
	while (true) {
		visited.assign(visited.size(), false);
		int64_t flow = dfs(start_vertex, INT_MAX, capacity, f);

		if (flow == 0) break;

		maxflow += flow;
	}
	return maxflow;
}

int main() {
	int64_t m;

	cin >> end_vertex >> m;

	vector<vector<int64_t>> capacity(end_vertex + 1, vector<int64_t>(end_vertex + 1));
	vector<vector<int64_t>> f(end_vertex + 1, vector<int64_t>(end_vertex + 1, 0));

	visited.resize(end_vertex + 1);
	graph.resize(end_vertex + 1);


	for (int i = 0; i < m; ++i) {
		int64_t i1, j, cap;
		cin >> i1 >> j >> cap;
		graph[i1].emplace_back(j);
		graph[j].emplace_back(i1);
		capacity[i1][j] = cap;
	}

	int64_t maxflow = ford_fulkerson(capacity, f);
	cout << maxflow;
}
