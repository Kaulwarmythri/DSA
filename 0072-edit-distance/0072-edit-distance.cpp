class Solution {
    int m, n;
    vector<vector<int>> dp;
public:
    int minDistance(string s, string t) {
        m = s.size(); n = t.size();
        dp.resize(m+1, vector<int>(n+1, -1));
        
        return solve(s, t, m, n);
    }
    
    int solve(string s, string t, int m, int n) {
        if(m == 0) return n;
        
        if(n == 0) return m;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        if(s[m-1] == t[n-1]) return dp[m][n] = solve(s, t, m-1, n-1);
        
        return dp[m][n] = 1 + min({solve(s, t, m-1, n-1), solve(s, t, m, n-1), solve(s, t, m-1, n)});
    }
};