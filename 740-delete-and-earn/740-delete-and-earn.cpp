class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        
        vector<int> v(n+1, 0), dp(n+1, 0);
        
        for(auto num : nums) v[num] += num;
        dp[0] = 0;
        dp[1] = v[1];
        
        for(int i=2; i<=n; i++){
            dp[i] = max(dp[i-1], v[i]+dp[i-2]);
        }
        return dp[n];
    }
};