#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void bellman_ford(vector<vector<pair<int, int>>>& graph, int src, int max_weight) {
	int n = graph.size();
	vector<int> dist(n, INF);
	vector<pair<int, int>> pred(n);
	vector<vector<int>> shortest_path(n + 1);
	dist[src] = 0;
	for (int i = 0; i < n - 1; i++) {
		bool any_update = false;
		for (int from = 1; from < n; from++) {
			for (auto& [to, weight] : graph[from]) {
				if (dist[from] != INF and dist[from] + weight < dist[to]) {
					dist[to] = dist[from] + weight;
					pred[to] = make_pair(from, weight);
					any_update = true;
				}
			}
			if (!any_update) {
				break;
			}

		}
	}

	int start_of_cycle = -1;
	for (int from = 1; from < n; from++) {
		for (auto& [to, weight] : graph[from]) {
			if (dist[from] != INF and dist[from] + weight < dist[to]) {
				start_of_cycle = to;
				
			}
		}
	}



	int v1 = std::numeric_limits<int>::min(); 

	if (start_of_cycle == -1) {
		cout << "YES\n";
		return;
	}


	if (start_of_cycle != -1) {
		int v = start_of_cycle;


		for (int i = 2; i < n; i++) {
			v = pred[v].first;
		}

		int u = v;

		u = pred[u].first;
		v1 += pred[v].second;

		while (u != v) {
			v1 += pred[u].second;
			if (v1 >= max_weight) {
				cout << "NO\n";
				return;
			}
			u = pred[u].first;
		}
	}


	if (v1 == std::numeric_limits<int>::min()) {
		cout << "YES\n";
		return;
	}

	if (abs(v1) < max_weight) {
		cout << "YES\n";
		return;
	}
	if (abs(v1) >= max_weight) {
		cout << "NO\n";
	}
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int amount_of_graphs, max_weight, n, m, src = 1;
	cin >> amount_of_graphs >> max_weight;

	for (int i = 0; i < amount_of_graphs; ++i) {
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int, int>>> graph(n + 1);
		for (int j = 0; j < m; j++) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u].emplace_back(v, w);
		}
		bellman_ford(graph, src, max_weight);
	}
}