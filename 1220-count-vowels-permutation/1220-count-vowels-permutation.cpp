class Solution {
    vector<vector<int>> m{{1}, {0,2}, {0,1,3,4}, {2,4}, {0}, {0,1,2,3,4}};
    
    int mod = pow(10, 9) + 7;
    vector<vector<int>> dp;
public:
    int countVowelPermutation(int n) {
        dp.resize(n+1, vector<int>(6, 0));
        return solve(n);
    }
    
    int solve(int n, char prev = 5) {
        if(n == 0) return 1;
        
        if(dp[n][prev])return dp[n][prev];
        
        int ans = 0;
        
        for(auto &i : m[prev]) {
            dp[n][prev] = (dp[n][prev] + solve(n-1, i))% mod;
        }
        return dp[n][prev];
    }
};