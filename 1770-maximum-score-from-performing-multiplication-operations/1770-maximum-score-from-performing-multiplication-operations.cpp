class Solution {
    vector<vector<int>> dp;
    int n, m;
public:
    int solve(int i, int j, vector<int> &nums, vector<int> &M){
        if (j == m) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        
        int left = solve(i + 1, j + 1, nums, M) + (nums[i] * M[j]);
        int right = solve(i, j + 1, nums, M) + (nums[(n - 1) - (j - i)] * M[j]);
        
        return dp[i][j] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& M) {   
        n = nums.size(), m = M.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, 0, nums, M);
    }
};