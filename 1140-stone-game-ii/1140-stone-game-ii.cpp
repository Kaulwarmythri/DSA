class Solution {
    int n;
    vector<vector<int>> dp;
public:
    int stoneGameII(vector<int>& P) {
        n = P.size();
        
        dp.resize(101, vector<int>(202, 0));
        
        int sum = accumulate(P.begin(), P.end(), 0), diff = solve(P, 0, 1);
        return (sum + diff) / 2;
    }
    
    int solve(vector<int> &P, int i, int m) {
        if(i >= n) return 0;
        
        if(dp[i][m] != 0) return dp[i][m];
        
        int ans = INT_MIN, total = 0;
        for(int j=0; j < 2 * m; j++) {
            if(i + j < n) total += P[i + j];
            ans = max(ans, total - solve(P, i+j+1, max(m, j+1)));
        }
        return dp[i][m] = ans;
    }
};