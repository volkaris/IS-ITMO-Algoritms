#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

class UnionFind {
public:
    UnionFind(int v) : parent(v+1), rank(v+1, 0) {
        for (int i = 0; i < v; ++i) {
            parent[i] = i;
        }
    }

 [[nodiscard]]   int find_set(int v) {
     if (v == parent[v])
         return v;
     return parent[v] = find_set(parent[v]);
    }

  void union_sets(int a, int b) {
         a = find_set(a);
         b = find_set(b);

        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
            }
            else if (rank[a] > rank[b]) {
                parent[b] = a;
            }
            else {
                parent[b] = a;
                ++rank[a];
            }
            
        }
        
    }

private:
    vector<int> parent;
    vector<int> rank; 
};


struct Requests {
    char request;
    pair<int, int> para;
    Requests(char ch,int first,int second): request(ch),para({first,second}) {}
};
                                               
int main() {



    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph;
    vector <Requests> requestses;

    graph.resize(n + 1);
    // empty_graph.resize(n + 1);
    requestses.reserve(q);

    for (size_t i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    UnionFind connectivity_components(n);

    for (size_t i = 0; i < q; ++i) {
        char command;
        cin >> command;
        if (command == '?') {
            int u, v;
            cin >> u >> v;

            requestses.emplace_back(Requests( command,u, v));
           

        }
        else if (command == '-') {
            int u, v;
            cin >> u >> v;
           
            requestses.emplace_back(Requests(command, u, v));
           
            auto it = ranges::find(graph[u], v);
            graph[u].erase(it);
            it = ranges::find(graph[v], u);
            graph[v].erase(it);
        }
    }


    vector<int> result;

    ranges::reverse(requestses);

     for (int i=0;i<graph.size();++i) {
	     for (int j=0;j<graph[i].size(); ++j) {
             connectivity_components.union_sets(i, graph[i][j]);
	     }
     }

    for (int i=0;i<requestses.size();++i) {
	    if (requestses[i].request=='?') {
            result.emplace_back  (connectivity_components.find_set(requestses[i].para.first) == connectivity_components.find_set(requestses[i].para.second));
	    }
        else {
            connectivity_components.union_sets(requestses[i].para.first, requestses[i].para.second);

        }
    }


    ranges::reverse(result);

    for (const auto& i:result) {
	    if (i==true) {
            cout << "YES\n";
	    }
        else {
            cout << "NO\n";
        }
    }


}
