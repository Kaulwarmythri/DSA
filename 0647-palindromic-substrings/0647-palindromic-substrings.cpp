class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i=0; i<n; i++) dp[i][i] = true, ans++;
        
        for(int gap=1; gap<n; gap++) {
            for(int i=0, j=gap; j<n; i++, j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = i == j-1 ? 1 : dp[i+1][j-1];
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};