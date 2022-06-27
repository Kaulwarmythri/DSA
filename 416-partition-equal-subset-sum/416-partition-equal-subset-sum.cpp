class Solution {
    vector<vector<int>> dp;
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        
        dp.resize(nums.size()+1, vector<int>(sum+1, -1));
        
        return canDo(nums, sum/2);
    }
    
    bool canDo(vector<int>& nums, int sum, int i=0) {
        if(sum == 0) return true;
        
        if(sum < 0 || i >= nums.size()) return false;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        return dp[i][sum] = canDo(nums, sum-nums[i], i+1) || canDo(nums, sum, i+1);
    }
};