class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& I) {
        sort(I.begin(), I.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        
        int ans = 0, prev = INT_MIN;
        for(auto &i: I) {
            if(i[0] < prev) ans++;
            else prev = i[1];
        }
        
        return ans;
    }
};