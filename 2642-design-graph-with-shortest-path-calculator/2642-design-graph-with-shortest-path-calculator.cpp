class Graph {
    vector<vector<pair<int, int>>> G;
public:
    Graph(int n, vector<vector<int>>& edges) {
        G.resize(n);
        
        for(auto &e: edges) 
            G[e[0]].push_back({e[1], e[2]});
    }
    
    void addEdge(vector<int> e) {
        G[e[0]].push_back({e[1], e[2]});
    }
    
    int shortestPath(int s, int e) {
        int n = G.size();
        
        vector<int> dist(n, INT_MAX); dist[s] = 0;

        // Priority queue to efficiently retrieve the node with the minimum distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            
            if (cost > dist[u])
                continue;

            if(u == e)
                return cost ;

            for (auto &[v, w] : G[u]) {
                
                if (dist[v] > w + dist[u]) {
                    dist[v] = w + dist[u];
                    pq.push({dist[v], v});
                }
            }
        }

        return ((dist[e] == INT_MAX) ? -1 : dist[e]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */