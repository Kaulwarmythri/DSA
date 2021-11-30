class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        
        vector<int> v(n+1, 0), dp(n+1, 0);
        for(auto num : nums) v[num] += num;
        
        dp[0]=v[0];
        dp[1] = max(v[0], v[1]);
        
        for(int i=2;i<n+1;i++) dp[i] = max(dp[i-2]+v[i], dp[i-1]);
        
        return dp.back();
     }
};