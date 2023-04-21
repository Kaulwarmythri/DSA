class Solution {
public:
    int profitableSchemes(int G, int P, vector<int> group, vector<int> profit) {
        vector<vector<int>> dp(P + 1, vector<int>(G + 1, 0));
        dp[0][0] = 1;
        int res = 0, mod = 1e9 + 7;
        for (int k = 0; k < group.size(); k++) {
            int g = group[k], p = profit[k];
            for (int i = P; i >= 0; i--)
                for (int j = G - g; j >= 0; j--)
                    dp[min(i + p, P)][j + g] = (dp[min(i + p, P)][j + g] + dp[i][j]) % mod;
        }
        for (int x: dp[P]) res = (res + x) % mod;
        return res;
    }
};

// int profitableSchemes(int n, int mp, vector<int>& G, vector<int>& P) {
        
//         dp.resize(mp + 1, vector<vector<int>>(n+1, vector<int>(G.size(), -1)));
        
//         return solve(G, P, mp, n, 0);
// }
    
// int solve(vector<int> &G, vector<int> &P, int mp, int n, int i) {
//     if (n < 0) return 0; 

//     if (i == G.size()) {

//         if (mp > 0) return 0; 
//         else return 1; 
//     }

//     if (dp[mp][n][i] != -1) return dp[mp][n][i];

//     int inc = solve(G, P, mp - P[i], n - G[i], i + 1);
//     int exc = solve(G, P, mp, n, i + 1);

//     return dp[mp][n][i] = (inc + (long long)exc) % MOD;
// }