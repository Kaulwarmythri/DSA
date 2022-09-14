#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        
        for(auto& r: roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }
        
        return dijkstra(graph, n, 0);
    }
    
    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        
        ways[src] = 1; dist[src] = 0;
        
        priority_queue<pll, vector<pll>, greater<>> pq; pq.push({0, 0});
        
        while (!pq.empty()) {
            auto[d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue; 
            
            for(auto [v, time] : graph[u]) {
                if (dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if (dist[v] == d + time) 
                    ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
        return ways[n-1];
    }
};