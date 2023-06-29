class Solution {
public:
    int maximumDetonation(vector<vector<int>>& B) {
        int n = B.size(), ans = INT_MIN;
        
        vector<vector<int>> G(n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j) {
                    long long x = abs(B[i][0] - B[j][0]), y = abs(B[i][1] - B[j][1]), r = B[i][2];
                    
                    if(x*x + y*y <= r*r) 
                        G[i].push_back(j);
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            vector<bool> vis(n);
            int cur = 0;
            
            dfs(G, i, vis, cur);
            ans = max(ans, cur);
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>> &G, int i, vector<bool> &vis, int &ans) {
        vis[i] = true;
        ans++;
        
        for(auto &j: G[i]) {
            if(!vis[j]) dfs(G, j, vis, ans);
        }
    }
};