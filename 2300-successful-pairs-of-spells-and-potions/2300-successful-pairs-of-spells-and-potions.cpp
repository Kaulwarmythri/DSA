class Solution {
public:
    vector<int> successfulPairs(vector<int>& S, vector<int>& P, long long success) {
        sort(P.begin(), P.end());
        
        vector<int> ans;
        for(auto &x: S) {
            long req = (success % x != 0) ? 1 + success / x : success / x;
            auto it = lower_bound(P.begin(), P.end(), req);
            
            ans.push_back(P.end() - it);
        }
        return ans;
    }
};