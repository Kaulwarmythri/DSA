class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), l, h, gap=1;
        
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(; gap < n; gap++) {
            for(l=0, h=gap; h < n; l++, h++) {
                dp[l][h] = (s[l] == s[h]) ? dp[l+1][h-1] : 1 + min(dp[l][h-1], dp[l+1][h]);
            }
        }
        return dp[0][n-1];
    }
};