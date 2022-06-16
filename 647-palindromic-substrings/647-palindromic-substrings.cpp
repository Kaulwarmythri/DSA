class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int i=0; i<n; i++) dp[i][i] = true, ans++;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(s[i] == s[j]) {
                    if(i-j == 1 || dp[i-1][j+1]) {
                        dp[i][j] = true;
                        ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};