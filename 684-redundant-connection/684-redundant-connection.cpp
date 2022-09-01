class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        vector<bool> vis(n+1, false);
        
        for(auto &e: edges) {
            fill(vis.begin(), vis.end(), false);
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            if(dfs(graph, e[0], vis))
                return e;
        }
        return {};
    }
 
    bool dfs(vector<vector<int>> &G, int curr, vector<bool> &vis, int par = -1) {
        if(vis[curr])
            return true;
        vis[curr] = true;
        
        for(auto &child: G[curr]) {
            if(child != par && dfs(G, child, vis, curr))
                return true;
        }
        return false;
    }
};