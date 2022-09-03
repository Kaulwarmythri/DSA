class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
        int n = G.size();
        vector<bool> vis(n, false), mark(n, false), cycle(n, false);
        vector<int> safe;
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) dfs(G, i, vis, mark, cycle);
        }
        
        for(int i=0; i<n; i++) {
            if(!cycle[i]) safe.push_back(i);
        }
        return safe;
    }
    
    bool dfs(vector<vector<int>> &G, int i, vector<bool> &vis, vector<bool> &mark, vector<bool> &cycle) {
        if(!vis[i]) {
            vis[i] = true;
            mark[i] = true;
            
            for(auto &child: G[i]) {
                if(!vis[child] && dfs(G, child, vis, mark, cycle))
                    return cycle[i] = true;
                else if(mark[child])
                    return cycle[i] = true;
            }
        }
        mark[i] = false;
        return false;
    }
};

