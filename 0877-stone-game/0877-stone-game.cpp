class Solution {
public:
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) dp[i][i] = p[i];
        
        for(int gap=1; gap<n; gap++) {
            for(int i=0, j=gap; j<n; i++, j++) {
                dp[i][j] = max(p[i] - dp[i+1][j], p[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};