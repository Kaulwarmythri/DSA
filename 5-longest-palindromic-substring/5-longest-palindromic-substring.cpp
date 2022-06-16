class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int i=0; i<n; i++) dp[i][i] = true;
        
        string ans = "";
        ans += s[0];
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(s[i] == s[j]) {
                    if(i-j == 1 || dp[i-1][j+1]) {
                        dp[i][j] = true;
                        if(i-j+1 > ans.size()) ans = s.substr(j, i-j+1);
                    }
                }
            }
        }
        return ans;
    }
};