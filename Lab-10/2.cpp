#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<bool> visited;
size_t n;
vector<vector<int>> graph;
size_t current_component = 0;
vector<unordered_set<size_t>> list_of_vertices_and_their_component;

void dfs(size_t node) {
    visited[node] = true;
    list_of_vertices_and_their_component[current_component].insert(node);
    for (size_t child : graph[node]) {
        if (!visited[child]) {
            dfs(child);
        }
    }
}

void start_dfs() {
    for (size_t i = 1; i <= n; i++) {
        if (!visited[i]) {
            ++current_component;
            dfs(i);
        }
    }
}

int main() {
 
    size_t m, q;
    cin >> n >> m >> q;

    graph.resize(n + 1);
    list_of_vertices_and_their_component.resize(n + 1);

    for (size_t i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited.assign(n + 1, false);

    for (size_t i = 0; i < q; ++i) {
        char command;
        cin >> command;
        if (command == '?') {
            int u, v;
            cin >> u >> v;
            visited.assign(n + 1, false);
            current_component = 0;
            start_dfs();
            bool found = false;
            for (const auto& j : list_of_vertices_and_their_component) {
                if (j.count(u) && j.count(v)) {
                    cout << "YES" << "\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "NO" << "\n";
            }
        }
        else if (command == '-') {
            int u, v;
            cin >> u >> v;
            auto it = find(graph[u].begin(), graph[u].end(), v);
            graph[u].erase(it);
            it = find(graph[v].begin(), graph[v].end(), u);
            graph[v].erase(it);
            list_of_vertices_and_their_component.clear();
            list_of_vertices_and_their_component.resize(n + 1);
            /*list_of_vertices_and_their_component[u].clear();
            list_of_vertices_and_their_component[v].clear();*/
        }
    }
}
