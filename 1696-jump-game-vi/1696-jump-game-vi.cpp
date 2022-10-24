class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        multiset<int> s({dp[0] = nums[0]});
        
        for(int i=1; i<n; i++) {
            if(i > k) s.erase(s.find(dp[i-k-1]));
            s.insert(dp[i] = nums[i] + *s.rbegin());
        }
        return dp[n-1];
    }
};