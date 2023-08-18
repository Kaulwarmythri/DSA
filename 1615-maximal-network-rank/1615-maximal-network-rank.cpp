class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& R) {
        vector<unordered_set<int>> G(n);
        
        for(auto &r: R) {
            G[r[0]].insert(r[1]);
            G[r[1]].insert(r[0]);
        }
        
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int rank = G[i].size() + G[j].size();
                if(G[i].count(j)) rank--;
                
                ans = max(ans, rank);
            }
        }
        return ans;
    }
};