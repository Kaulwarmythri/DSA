class Solution {
    int n;
    vector<int> color;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
        n = G.size();
        color.resize(n, 0);
        
        vector<int> ans;
        for(int i=0; i<n; i++) 
            if(color[i] == 2 || dfs(G, i)) 
                ans.push_back(i);
        
        return ans;
    }
    
    bool dfs(vector<vector<int>> &G, int i) {
        if(color[i] == 2) return true;
        
        color[i] = 1;
        for(auto &j: G[i]) {
            if(color[j] == 0 && !dfs(G, j) || color[j] == 1) return false;
        }
        color[i] = 2;
        return true;
    }
};