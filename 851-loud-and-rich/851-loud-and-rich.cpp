class Solution {
    vector<vector<int>> G;
    vector<int> res;
    int n;
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        n = quiet.size();
        G.resize(n);
        for (auto v : richer) 
            G[v[1]].push_back(v[0]);
        res = vector<int> (n, -1);
        
        for (int i = 0; i < n; i++) 
            dfs(i, quiet);
        return res;
    }

    int dfs(int i, vector<int>& quiet) {
        if (res[i] >= 0) 
            return res[i];
        res[i] = i;
        for (int j : G[i]) 
            if (quiet[res[i]] > quiet[dfs(j, quiet)]) 
                res[i] = res[j];
        
        return res[i];
    }
};