class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
        int n = G.size();
        vector<int> color(n, 0), safe;
        
        for(int i=0; i<n; i++) {
            if(color[i] == 2|| !dfs(G, i, color))
                safe.push_back(i);
        }
        return safe;   
    }
    
    bool dfs(vector<vector<int>> &G, int curr, vector<int> &color) {
        color[curr] = 1;
        
        for(auto &child: G[curr]) {
            if((color[child] == 0 && dfs(G, child, color)) || color[child] == 1)
                return true;
        }
        color[curr] = 2;
        return false;
    }
};