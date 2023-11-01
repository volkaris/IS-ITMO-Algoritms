#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>

using namespace std;

const int INF = numeric_limits<int>::max();


vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph) {

	size_t n = graph.size();
    vector<int> dist(n, INF);
   

	dist[start] = 0;

    priority_queue < pair<int, int>, vector<pair<int, int>>, less <pair<int, int>> > pq;

    pq.push(make_pair(start, 0));  

    while (!pq.empty()) {
        int cur_vertex = pq.top().first;
     

    	pq.pop();

        for (const auto& neighbor : graph[cur_vertex]) {



        	const int weight_of_edge = neighbor.second;

        	if (dist[cur_vertex] + weight_of_edge < dist[neighbor.first]) {

                dist[neighbor.first] = dist[cur_vertex] + weight_of_edge;

        		pq.push(make_pair(neighbor.first, dist[cur_vertex] + weight_of_edge));

            }
        }
    }

    return dist;
}

int main() {
    int n, m, start, amount_of_requests;
    cin >> n >> m >>amount_of_requests >> start;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight);
    }

    vector<int> dist = dijkstra(start, graph);
    vector <string> answer(amount_of_requests);
    for (int i = 0; i < amount_of_requests; ++i) {
        int end;
        cin >> end;
        if (dist[end] == INF) {
            cout << "-1\n";

        }
        else {
            cout << dist[end] << "\n";
        }

    }
}