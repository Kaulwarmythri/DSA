class Solution {
    int n;
    vector<vector<int>> ans;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& G) {
        n = G.size();
        vector<int> curr;
        
        dfs(G, 0, curr);
        
        return ans;
    }
    
    void dfs(vector<vector<int>> &G, int i, vector<int> &curr) {
        curr.push_back(i);
        if(i == n-1) {
            ans.push_back(curr);
        }
        for(auto &child: G[i]) {
            dfs(G, child, curr);
        }
        curr.pop_back();
    }
};