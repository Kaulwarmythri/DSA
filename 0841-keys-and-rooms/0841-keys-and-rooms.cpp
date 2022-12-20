class Solution {
    vector<bool> vis;
    int n;
public:
    bool canVisitAllRooms(vector<vector<int>>& G) {
        n = G.size();
        vis.resize(n, false);
        
        dfs(G, 0);
        for(int i=0; i<n; i++) if(!vis[i]) return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>> &G, int i) {
        vis[i] = true;
        
        for(auto &c: G[i]) {
            if(!vis[c]) dfs(G, c);
        }
    }
};