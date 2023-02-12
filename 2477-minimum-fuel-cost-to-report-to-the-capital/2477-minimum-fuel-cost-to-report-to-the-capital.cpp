class Solution {
    long long int ans = 0;
public:
    long long minimumFuelCost(vector<vector<int>>& R, int seats) {
        int n = R.size();
        
        vector<vector<int>> G(n+1);    //v-1 edges for v vertices (In a tree)
        
        for(auto &r: R) {
            G[r[0]].push_back(r[1]);
            G[r[1]].push_back(r[0]);
        }
        
        dfs(G, 0, 0, seats);
        return ans;
    }
    
    int dfs(vector<vector<int>> &G, int i, int pre, int seats, int people = 1) {
        for(auto &x: G[i]) {
            if(x == pre) continue;
            
            people += dfs(G, x, i, seats);
        }
        
        if(i != 0) ans += (people + seats - 1) / seats;
        return people;
    }
};