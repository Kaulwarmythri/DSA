class Solution {
    int dp[5001][4][4][4], colors[3] = {1, 2, 3};
    int mod = 1e9+7;
public:
    int numOfWays(int n) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        
        for(auto c1: colors) {
            for(auto c2: colors) {
                for(auto c3: colors) {
                    ans += dfs(0, n, 0, 0, 0, c1, c2, c3) % mod;
                    ans %= mod;
                }
            }
        }
        return ans;
    }
    
    int dfs(int row, int n, int prc1, int prc2, int prc3, int c1, int c2, int c3) {
        if((c1 == c2 || c2 == c3) || (prc1 == c1 || prc2 == c2 || prc3 == c3)) 
            return 0;
        if(dp[row][c1][c2][c3] != -1) 
            return dp[row][c1][c2][c3];
        
        if(row == n-1) return 1;
        
        long long int ans = 0;
        for(auto &nc1: colors) {
            for(auto &nc2: colors) {
                for(auto &nc3: colors) {
                    ans += dfs(row+1, n, c1, c2, c3, nc1, nc2, nc3) % mod;
                    ans %= mod;
                }
            }
        }
        return dp[row][c1][c2][c3] = ans % mod;
    }
};