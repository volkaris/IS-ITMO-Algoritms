#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

const  int INF = numeric_limits<int>::max();


auto floyd_warshall(vector<vector<int>>& graph, int n) {

   // vector<vector<int>> dist(n, vector<int>(n, INF));


    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j) {
                dist[i][j] = 0;
            }


            dist[i][j] = graph[i][j];


        }
    }*/


    for (int k = 0; k < n; k++) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (graph[i][k] != INF and graph[k][j] != INF and graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }


   // return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            }
        }

    }
    for (int i = 0; i < m; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        graph[start][end] = weight;
        graph[end][start] = weight;
    }

    floyd_warshall(graph, n + 1);

    int max_value = 0;

    for (const auto& i : graph) {
        for (const auto& j : i) {
            if (j != INF and j > max_value) {
                max_value = j;
            }
        }
    }


    cout << max_value;



}