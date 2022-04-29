class Solution {
    vector<int> vis, color;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vis.resize(n, 0); color.resize(n, 0);
        
        for(int i=0; i<n; i++) {
            if(!vis[i] && !dfs(graph, i, 0)) return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>> &graph, int u, int c) {
        vis[u] = 1;
        color[u] = c;
        
        for(int adj : graph[u]) {
            if(!vis[adj]) {
                if(!dfs(graph, adj, c^1)) return false;
            }else {
                if(color[adj] == color[u]) return false;
            }
        }
        return true;
    }
};
