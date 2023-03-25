class Solution {
    unordered_map<int, vector<int>> G;
    vector<int> vis;
public:
    long long countPairs(int n, vector<vector<int>>& E) {
        long long ans = (long long) n * (n - 1) / 2;
        
        for(auto &e: E) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        
        vis.resize(n, 0);
        for(int i=0; i<n; i++) {
            long long count = 0;
            if(!vis[i]) dfs(i, count);
            
            ans -= count * (count - 1) / 2;
        }
        return ans;
    }
    
    void dfs(int node, long long &count) {
        vis[node] = 1;
        count++;
        
        for(auto &v: G[node]) {
            if(!vis[v]) dfs(v, count);
        }
    }
};