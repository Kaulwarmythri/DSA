bool compare(vector<int> &a, vector<int> &b) {
    return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& E) {
        sort(E.begin(), E.end(), compare);
        
        vector<int> dp;
        
        for(auto e : E) {
            auto it = lower_bound(dp.begin(), dp.end(), e[1]);
            if(it == dp.end()) dp.push_back(e[1]);
            
            else *it = e[1];
        }
        return dp.size();
    }
};