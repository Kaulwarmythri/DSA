class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& Req, vector<vector<string>>& P) {
        int n = Req.size(), people = P.size();
        
        unordered_map<string, int> m;
        unordered_map<int, vector<int>> dp;
        dp.reserve(1<<n);
        dp[0] = {};
        
        for(int i=0; i<n; i++) 
            m[Req[i]] = i;
        
        for(int i=0; i<people; i++) {
            int cur_skill = 0;
            
            for(auto &s: P[i]) 
                cur_skill |= 1 << m[s];
                
            for(auto it = dp.begin(); it != dp.end(); it++) {
                int comb = cur_skill | it->first;
                
                if(dp.find(comb) == dp.end() || dp[comb].size() > 1+it->second.size()) {
                    dp[comb] = it->second;
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};