class Solution {
    string s;
    int k, n;
    int dp[105][105];
public:
    int getLengthOfOptimalCompression(string str, int K) {
        s = str; n = str.size(); k = K;
        
        memset(dp, -1, sizeof(dp));
        
        return solve(0, k);
    }
    
    int solve(int start, int k) {
        if(start >= n || n - start <= k) 
            return 0;
        
        if(dp[start][k] != -1)
            return dp[start][k];
        
        int cnt[26] = {}; int ans = INT_MAX;
        
        for(int i=start, most = 0; i<n; i++) {
            most = max(most, ++cnt[s[i] - 'a']);
            if(k >= i - start + 1 - most) {
                ans = min(ans, 1 + encode(most) + solve(i+1, k - (i - start + 1 - most)));
            }
        }
        return dp[start][k] = ans;
    }
    
    int encode(int x) {
        return x == 1 ? 0 : x < 10 ? 1 : x < 100? 2 : 3;
    }
};