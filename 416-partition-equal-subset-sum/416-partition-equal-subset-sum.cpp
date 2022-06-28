class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if(totalSum & 1) return false;
        
        vector<int> dp(totalSum+1, -1);
        
        return solve(nums, totalSum / 2, dp);
    }
    bool solve(vector<int>& nums, int sum, vector<int> &dp, int i = 0) {
        if(sum == 0) return true;  
        
        if(i >= size(nums) || sum < 0) return false; 
        
        if(dp[sum] != -1) return dp[sum];
        
        
        return dp[sum] = solve(nums, sum-nums[i], dp, i+1) || solve(nums, sum, dp, i+1);         
    }

};