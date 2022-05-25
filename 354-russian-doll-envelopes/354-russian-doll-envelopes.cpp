class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& E) {
        sort(E.begin(), E.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        vector<int> dp;
        for (auto& env : E) {
            
            auto it = lower_bound(dp.begin(), dp.end(), env[1]);
            
            if (it == dp.end()) dp.push_back(env[1]);
            
            else *it = env[1];
        }
        
        return dp.size();
    }
};