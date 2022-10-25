class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<set<int>> G(n);
        vector<int> cnt(n, 0);
        
        int ans = INT_MAX;
        
        for(auto &e: edges) {
            G[min(e[0], e[1]) - 1].insert(max(e[0], e[1]) - 1);
            
            cnt[e[0] - 1]++;
            cnt[e[1] - 1]++;
        }
        
        for(int i=0; i<n; i++) {
            for(auto j=G[i].begin(); j != G[i].end(); j++) {
                for(auto k=next(j); k != G[i].end(); k++) {
                    if(G[*j].count(*k)) {
                        ans = min(ans, cnt[i] + cnt[*j] + cnt[*k] - 6);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};