class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& G) {
        int n = G.size();
        vector<bool> vis(n, false);
        
        dfs(G, 0, vis);
        
        for(int i=0; i<n; i++) {
            if(!vis[i])
                return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>> &G, int curr, vector<bool> &vis) {
        vis[curr] = true;
        
        for(auto &child: G[curr]) {
            if(!vis[child])
                dfs(G, child, vis);
        }
    }
};