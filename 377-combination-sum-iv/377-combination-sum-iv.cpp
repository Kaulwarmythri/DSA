class Solution {
public:
    int combinationSum4(vector<int>& nums, int X) { 
        vector<int> dp(X+1, -1);
        dp[0] = 1;
        
        return solve(nums, X, dp);
    }
    
    int solve(vector<int> &nums, int X, vector<int> &dp) {
        if(dp[X] != -1) return dp[X];
        
        int ans = 0;
        
        for(auto num: nums) {
            if(num <= X) ans += solve(nums, X-num, dp);
        }
        return dp[X] = ans;
    }
};