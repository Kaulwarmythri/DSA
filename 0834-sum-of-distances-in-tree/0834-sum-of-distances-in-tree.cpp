class Solution {
    vector<vector<int>> T;
    vector<int> count, ans;
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& E) {
        T.resize(n);
        
        for(auto &e: E) {
            T[e[0]].push_back(e[1]);
            T[e[1]].push_back(e[0]);
        }
        
        count.resize(n, 1);
        ans.resize(n, 0);
        
        dfs1(0, -1);
        dfs2(0, -1);
        
        return ans;
    }
    
    void dfs1(int root, int par) {
        for(auto &c: T[root]) {
            if(c == par) continue;
            
            dfs1(c, root);
            
            count[root] += count[c];
            ans[root] += ans[c] + count[c];
        }
    }
    
    void dfs2(int root, int par) {
        for(auto &c: T[root]) {
            if(c == par) continue;
            
            ans[c] = ans[root] - count[c] + T.size() - count[c];
            dfs2(c, root);
        }
    }
};