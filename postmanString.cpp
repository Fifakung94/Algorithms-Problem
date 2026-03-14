#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    string S, T; 
    cin >> N >> M >> S >> T; 

    unordered_map<string, vector<pair<string, int>>> adj;
    unordered_map<string, int> dist;

    for (int i = 0; i < M; i++) {
        string u, v; 
        int w;
        cin >> u >> v >> w; 
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        dist[u] = INF;
        dist[v] = INF;
    }

    // ----- Dijkstra's Algorithm -----

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    dist[S] = 0; 
    pq.push({0, S}); 

    while (!pq.empty()) {
        int d = pq.top().first;  
        string u = pq.top().second; 
        pq.pop();

        if (u == T) break;
        if (d > dist[u]) continue;

        for (int i = 0; i < adj[u].size(); i++) {
            string v = adj[u][i].first;     
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
