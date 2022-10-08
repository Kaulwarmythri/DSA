class Solution {
    int n, dp[101][101], C[101][101];
    const int inf = 1e2+5;
public:
    int calc(string& s, int i, int j){
        if(i >= j) 
            return 0;
        if(C[i][j] != -1) 
            return C[i][j];
        return C[i][j] = (s[i] != s[j]) + calc(s, i+1, j-1);
    }
    
    int partition(string &s, int i, int k){
        if(k == 0) return calc(s, i, n-1);
        if(i == n) return inf;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        int ans = inf;
        for(int l=i; l<n-1; l++){
            ans = min(ans, calc(s, i, l) + partition(s, l+1, k-1));
        }
        return dp[i][k] = ans;
    }
    
    int palindromePartition(string s, int k) {
        n = s.size();
        memset(C, -1, sizeof(C));
        memset(dp, -1, sizeof(dp));
        
        return partition(s, 0, k-1);
    }
};