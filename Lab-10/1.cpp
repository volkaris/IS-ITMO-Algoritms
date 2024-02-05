#include <iostream>
#include <vector>

using namespace std;

bool got_cycle = false;
vector<bool> visited;
vector<bool> is_there_trap;
vector<vector<int>> graph;
size_t current_component = 0;
vector<size_t> list_of_vertices_and_their_component;
vector<size_t> is_there_trap_in_comp;

void dfs(size_t node) {
	visited[node] = true;
	list_of_vertices_and_their_component[node] = current_component;
	for (size_t child : graph[node]) {
		if (!visited[child]) {
			list_of_vertices_and_their_component[child] = current_component;

			dfs(child);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	size_t amount_of_components = 0;
	size_t n, m;
	cin >> n >> m;

	graph.resize(n + 1);
	is_there_trap.resize(n + 1);
	list_of_vertices_and_their_component.resize(n + 1);
	for (size_t i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (size_t i=1;i<=n;++i) {
		bool trap;
		cin >> trap;
		is_there_trap[i]=trap;
	}

	visited.assign(n + 1, false);

	for (size_t i = 1; i <= n; i++) {
		if (!visited[i]) {
			++amount_of_components;
			++current_component;
			dfs(i);
		}
	}
	is_there_trap_in_comp.resize(amount_of_components+1);
	for (size_t i=1;i<=n;++i) {
		 if (is_there_trap[i] == 1) {
			 is_there_trap_in_comp[list_of_vertices_and_their_component[i]] = true;
		 }
	}

	cout << amount_of_components << "\n";
	for (size_t i = 1; i < list_of_vertices_and_their_component.size(); ++i) {
		cout << list_of_vertices_and_their_component[i] << " ";
	}
	cout << "\n";
	for (size_t i = 1; i < is_there_trap_in_comp.size(); ++i) {
		cout << is_there_trap_in_comp[i] << " ";
	}
}
