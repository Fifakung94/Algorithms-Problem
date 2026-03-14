#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S, T;
    cin >> N >> M >> S >> T; 

    vector<vector<pair<int, int>>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // ----- Dijkstra's Algorithm -----
    
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[S] = 0;  
    pq.push({0, S});
    while (!pq.empty()) {
        int d = pq.top().first; 
        int u = pq.top().second;
        pq.pop();

        if (u == T) break;

        if (d > dist[u]) continue;

		for (int i = 0; i < adj[u].size(); i++) {
		    int v = adj[u][i].first;   
		    int weight = adj[u][i].second;  
		    
		    if (dist[u] + weight < dist[v]) {	
		        dist[v] = dist[u] + weight; 	
		        pq.push({dist[v], v});  		
		    }
		}
    }

    cout << dist[T] << "\n";
    return 0;
}
