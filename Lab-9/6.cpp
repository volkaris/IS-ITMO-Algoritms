#include <iostream>
#include <vector>
#include <set>
using namespace std;
size_t num_visited_ = 0;

bool dfs(size_t current_vertex, size_t current_depth, size_t& num_visited, vector<bool>& visited, const vector<vector < size_t >>& graph, size_t n) {

    visited[current_vertex] = true;
    ++num_visited;
    if (num_visited == n) {
        return true;
    }
    for (size_t i = 0; i < graph[current_vertex].size(); ++i) {
        if (graph[current_vertex].size() > 2) {
            return false;
        }
        const size_t to = graph[current_vertex][i];
        if (!visited[to]) {
            if (dfs(to, current_depth + 1, num_visited, visited, graph, n)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    size_t amount_of_connectivity_components = 0;
    vector<vector < size_t >> graph;
    vector<bool> visited;

    graph.resize(n + 1);
    visited.resize(n + 1);

    std::fill(visited.begin(), visited.end(), false);

    // connectivity_comp.assign(n + 1, false);
    for (size_t i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }


    if (dfs(1, 1, num_visited_, visited, graph, n)) {
        cout << "YES";
        return 0;
    }



    for (size_t i = 1; i <= n; ++i) {
        if (!visited[i]) {
            std::cout << "NO";
            return 0;
        }
    }

    cout << "NO";
}