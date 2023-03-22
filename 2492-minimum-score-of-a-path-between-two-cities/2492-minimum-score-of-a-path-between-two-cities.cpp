class Solution {
public:
    int minScore(int n, vector<vector<int>>& R) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> G(n+1);
        
        for(auto &e: R) {
            G[e[0]].push_back({e[1], e[2]});
            G[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> vis(n+1, 0);
        queue<int> q; q.push(1); vis[1] = 1;
        
        while(q.size()) {
            auto u = q.front(); q.pop();
            for(auto &[v, dis]: G[u]) {
                ans = min(ans, dis);
                
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};