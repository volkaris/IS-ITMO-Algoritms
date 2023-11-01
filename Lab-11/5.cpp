#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;





auto topologicalSort(vector<vector<pair<int64_t, int64_t>>>& graph, vector<int>& inDegree) {
    auto n = graph.size();
    queue<int64_t> q;
    vector<int> result;


    for (size_t i = 1; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }


    while (!q.empty()) {
        int64_t curr = q.front();
        q.pop();
        result.push_back(curr);

        for (const auto& neighbor : graph[curr]) {
            inDegree[neighbor.first]--;
            if (inDegree[neighbor.first] == 0) {
                q.push(neighbor.first);
            }
        }
    }


    return result;

}


void DAG(const vector<vector<pair<int64_t, int64_t>>>& graph, vector<int64_t>& distance, vector<int>& top_sort_order, vector<vector<int>>& shortest_path) {


    for (const auto& u : top_sort_order) {

        for (const auto& v : graph[u]) {
            if (distance[v.first] > distance[u] + v.second) {
                distance[v.first] = distance[u] + v.second;
               
            }
        }
    }




}



int main() {
    int n, m, start, end;
    cin >> n >> m >> start >> end;


    vector<vector<pair<int64_t, int64_t>>> graph(n + 1);
    vector inDegree(n + 1, 0);
    vector visited(n + 1, false);
    vector<vector<int>> shortest_path(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
        inDegree[v]++;
    }

    auto top_sort_order = topologicalSort(graph, inDegree);

    std::vector<int64_t> distance(n + 1, std::numeric_limits<int>::max());

    distance[start] = 0;
    DAG(graph, distance, top_sort_order, shortest_path);
    if (distance[end] == std::numeric_limits<int>::max()) {
        cout << "-1";
        return 0;
    }
    else {
        cout << distance[end];
    }
}
