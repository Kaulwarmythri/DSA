class Solution {
    int m, n;
    vector<vector<int>> dp;
public:
    int minDistance(string word1, string word2) {
        m = word1.size(); n = word2.size();
        dp.resize(m+1, vector<int>(n+1, -1));
        
        return solve(word1, word2, m, n, dp);
    }
    
    int solve(string s1, string s2, int m, int n, vector<vector<int>>&dp) {
        
        if(!m) dp[m][n] = n;
        
        if(!n) dp[m][n] = m;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        if(s1[m-1] == s2[n-1]) dp[m][n] = solve(s1, s2, m-1, n-1, dp);
        
        else {
            dp[m][n] = 1 + min({solve(s1, s2, m-1, n-1, dp), solve(s1, s2, m-1, n, dp), solve(s1, s2, m, n-1, dp)});
        }
        return dp[m][n];;
    }
    
};