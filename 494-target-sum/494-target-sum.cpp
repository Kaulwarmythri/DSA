class Solution {
    int n, ans = 0;
    vector<unordered_map<int, int>> dp;
public:
    int findTargetSumWays(vector<int>& nums, int X) {
        n = nums.size();
        dp.resize(n);
        return solve(nums, X, 0);

    }
    
    int solve(vector<int>& nums, int X, int i) {
        
        if(X == 0 && i == n) return 1;
        
        if(i == n) return 0;
        
        if(dp[i].find(X) != dp[i].end()) return dp[i][X];
        
        return dp[i][X] = solve(nums, X-nums[i], i+1) + solve(nums, X+nums[i], i+1);  
    }
};