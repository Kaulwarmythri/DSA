class Solution {
    int n;
    vector<int> dp;
    
public:
    int numDecodings(string s) {
        n = s.size();
        dp.resize(n+1, -1);
        dp[n] = 1;
        return s.empty() ? 0 : solve(s, 0, dp);
    }
    
    int solve(string s, int i, vector<int> &dp) {
        if(s[i] == '0') dp[i] = 0;
        if(dp[i] > -1) return dp[i];
        
        int res = solve(s, i+1, dp);
        if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
            res += solve(s, i+2, dp);
        
        return dp[i] = res;
    }
};