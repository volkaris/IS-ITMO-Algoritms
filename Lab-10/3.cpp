#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;


vector<unordered_set<size_t>> strongly_connected_comp;
size_t scc = 1;
void dfs(vector<vector<size_t>>& adj, size_t u, vector<bool>& visited, stack<size_t>& stk) {
    visited[u] = true;
    for (size_t v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, v, visited, stk);
        }
    }
    stk.push(u);
}

void reverse_dfs(vector<vector<size_t>>& adj, size_t u, vector<bool>& visited) {
    visited[u] = true;
    strongly_connected_comp[scc].emplace(u);
    for (size_t v : adj[u]) {
        if (!visited[v]) {
            
            reverse_dfs(adj, v, visited);
        }
    }
}

void kosaraju(size_t V, vector<vector<size_t>>& adj) {
    vector visited(V + 1, false);
    stack<size_t> stk;
    for ( size_t i = 1; i <= V; i++) {
        if (!visited[i]) {
            dfs(adj, i, visited, stk);
        }
    }

    vector<vector<size_t>> trans_adj(V + 1);
    for (size_t i = 1; i <= V; i++) {
        visited[i] = false;
        for (size_t j : adj[i]) {
            trans_adj[j].push_back(i);
        }
    }
   
    while (!stk.empty()) {
        size_t u = stk.top();
        stk.pop();
        if (!visited[u]) {
            reverse_dfs(trans_adj, u, visited);
            scc++;
        }
    }

}

int main() {
    size_t n, m,q;
    cin >> n >> m>>q;
    vector<vector<size_t>> adj(n + 1);
    for (size_t i = 0; i < m; i++) {
        size_t u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    strongly_connected_comp.resize(n + 1);
    kosaraju(n, adj);

    for (size_t requests=0;requests<q;++requests) {
        size_t start, end;
        cin >> start >> end;
        bool found = false;
        for(const auto& i:strongly_connected_comp) {
	        if (i.contains(start) and i.contains(end)) {
                cout << "YES"<<"\n";
                found = true;
                break;
	        }
           
        }
        if (!found) {
            cout << "NO\n";
        }
    }

}
