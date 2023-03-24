class Solution {
    int ans = 0;
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> G(n), outgoing(n);
        vector<bool> vis(n, false);
        
        for(auto &e: connections) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
            outgoing[e[0]].push_back(e[1]);
        }
        
        dfs(G, outgoing, vis, 0, -1);
        
        return ans;
    }
    
    void dfs(vector<vector<int>> &G, vector<vector<int>> &out, vector<bool> &vis, int i, int par) {
        vis[i] = true;
        if(par != -1) {
            if(find(out[i].begin(), out[i].end(), par) == out[i].end())
                ans++;
        }
        
        for(auto &j: G[i]) {
            if(!vis[j])
                dfs(G, out, vis, j, i);
        }
    }
};