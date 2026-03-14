#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int to;
    int weight;

    Edge(int t, int w) {
        this->to = t;
        this->weight = w;
    }
};

class Network {
	private:
	    int n;
	    vector<vector<Edge>> adj;
	
	public:
	    Network(int nodes) {
	        this->n = nodes;
	        adj.resize(n);
	    }
		
		void addConnection(int u , int v , int w){
			adj[u].push_back(Edge(v , w));
			adj[v].push_back(Edge(u , w));
		}
		
		int findShortestPath(int start , int target){
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			vector<int> dist(n, INT_MAX);
			
			dist[start] = 0;
			pq.push({0 , start});
			
			while(!pq.empty()){
				int d = pq.top().first;
				int u = pq.top().second;
				pq.pop();
				
				if(d > dist[u]) continue;
				
				if(u == target) return dist[u];
				
				for (int i = 0; i < adj[u].size(); i++) {
    				Edge edge = adj[u][i]; 
    				int v = edge.to;      
    				int w = edge.weight;  

    				if (dist[u] + w < dist[v]) {
        				dist[v] = dist[u] + w;
        				pq.push({dist[v], v});
    				}
				}
			}
			return -1;
		}
};

void solve() {
    int n, m, s, t;
    if (!(cin >> n >> m >> s >> t)) return;

    Network net(n); 
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        net.addConnection(u, v, w);
    }

    int result = net.findShortestPath(s, t);
    cout << result << endl;
}

int main(){
	int C;
    if (!(cin >> C)) return 0;
    while (C--) {
        solve();
    }
    return 0;
}
