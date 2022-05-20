class Solution {
    vector<vector<int>> dp;
    int m, n;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        m = og.size(), n = og[0].size();
        dp.resize(m, vector<int>(n));
        
        return solve(og, 0, 0);
    }
    
    int solve(vector<vector<int>> &og, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        
        if(og[i][j]) return dp[i][j] = 0;
        
        if(i == m-1 && j == n-1) return 1;
        
        if(dp[i][j]) return dp[i][j];
        
        return dp[i][j] = solve(og, i+1, j) + solve(og, i, j+1);
    }
};



