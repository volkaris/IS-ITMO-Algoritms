#include <iostream>
#include <vector>

using namespace std;

bool got_cycle = false;
vector<bool> visited;
vector<vector<int>> graph;

void dfs(size_t node, size_t parent) {
    visited[node] = true;
    for (size_t child : graph[node])
    {   if (!visited[child]) {
            dfs(child, node);
        }
        else if (child!=parent)
        {
            got_cycle = true;
            return;
        }
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    graph.resize(n + 1);

    for (size_t i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited.assign(n + 1, false);

    for (size_t i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
            if (got_cycle) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
}