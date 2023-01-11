class Solution {
    vector<vector<int>> T;
    vector<bool> vis;
public:
    int minTime(int n, vector<vector<int>>& E, vector<bool>& hasApple) {
        T.resize(n);
        vis.resize(n, false);
        
        for(auto &e: E) {
            T[e[0]].push_back(e[1]);
            T[e[1]].push_back(e[0]);
        }
        
        return dfs(T, hasApple, 0, 0) * 2;
    }
    
    int dfs(vector<vector<int>> &T, vector<bool> &hasApple, int node, int dis) {
        int ans = dis;
        vis[node] = true;
        
        for(auto &c: T[node]) {
            if(!vis[c]) {
                int temp = dfs(T, hasApple, c, dis + 1);
                if(temp)
                    ans += temp - dis;
            }
        }
        return hasApple[node] || ans > dis ? ans : 0;
    }
};