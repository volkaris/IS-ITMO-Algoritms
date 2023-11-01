#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

constexpr  int INF = numeric_limits<int>::max();

auto floyd_warshall(vector<vector<int>>& graph, int n,int max_difference) {
    vector<vector<int>> dist(n, vector<int>(n, INF));

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           
            
        	dist[i][j] = graph[i][j];
            
        }
    }

   
    for (int k = 0; k < n; k++) {
   
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               
                if ( abs(i-k)<=max_difference and abs(k-j)<=max_difference and   dist[i][k] != INF and dist[k][j] != INF and dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    
    return dist;
}

int main() {
    int n,m,k;
    cin >> n>>m>>k;
    vector<vector<int>> graph(n+1, vector<int>(n+1,INF ));
     for (int i=0;i<m;++i) {
         int start, end, weight;
         cin >> start>> end>>weight;
         graph[start][end] = weight;
     }
   
    

  auto answer=  floyd_warshall(graph, n+1,k);
  int amount_of_requests;
  cin >> amount_of_requests;
  for (int i = 0; i < amount_of_requests;++i) {
        int start, end;
        cin >> start>> end;
		if (answer[start][end]== INF) {
            cout << "-1\n";
		}
        else {
            cout << answer[start][end] << "\n";
        }
    }
}