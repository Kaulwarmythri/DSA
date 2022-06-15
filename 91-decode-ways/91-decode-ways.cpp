class Solution {
    int n;
    vector<int> dp;
public:
    int numDecodings(string s) {
        n = s.size();
        dp.resize(n+1, -1);
        dp[n] = 1;
        return solve(s, 0);
    }
    
    int solve(string s, int i) {
        if(s[i] == '0') return dp[i] = 0;
        if(dp[i] != -1) return dp[i];
        
        int res = solve(s, i+1);
        if(i < n-1 && (s[i] == '1' ||  (s[i] == '2' && s[i+1] < '7'))) res += solve(s, i+2);
        
        return dp[i] = res;
    }
};