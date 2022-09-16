class Solution {
    vector<vector<int>> dp;
    int n, m;
public:
    int solve(vector<int> &nums, vector<int> &M, int l, int i){
        if (i == m) return 0;
        if (dp[l][i] != INT_MIN) return dp[l][i];
        
        int left = solve(nums, M, l + 1, i + 1) + (nums[l] * M[i]);
        int right = solve(nums, M, l, i + 1) + (nums[(n - 1) - (i - l)] * M[i]);
        
        return dp[l][i] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& M) {   
        n = nums.size(), m = M.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(nums, M, 0, 0);
    }
};