class Solution {
    int m, n, p;
    vector<vector<int>> dp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size(); n = s2.size(); p = s3.size();
        dp.resize(m+1, vector<int>(n+1, -1));
        if(m + n != p) return false;
        return solve(s1, s2, s3, m-1, n-1, p-1);
    }
    
    bool solve(string s1, string s2, string s3, int m, int n, int p) {
        if(m < 0 && n < 0 && p < 0) return true;
        
        if(m >= 0 && n >= 0 && dp[m][n] != -1) return dp[m][n];
        
        if(m >= 0 && s1[m] == s3[p] && n >= 0 && s2[n] == s3[p]) {
            return dp[m][n] = solve(s1, s2, s3, m-1, n, p-1) || solve(s1, s2, s3, m,n-1,p-1);
        }
        else if(m >= 0 && s1[m] == s3[p]) return solve(s1, s2, s3, m-1, n, p-1);
        else if(n >= 0 && s2[n] == s3[p]) return solve(s1, s2, s3, m, n-1, p-1);
        
        return false;
    }
};