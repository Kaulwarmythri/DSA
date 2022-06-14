class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int sum1 = 0, sum2 = 0;
        
        for(auto c : s1) sum1 += c;
        for(auto c : s2) sum2 += c;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else {
                    dp[i][j] = (s1[i-1] == s2[j-1]) ? s1[i-1] + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int ans = dp[m][n];
        return sum1 - ans + sum2 - ans;
    }
};