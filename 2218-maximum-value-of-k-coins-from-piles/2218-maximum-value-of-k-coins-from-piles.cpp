class Solution {
    int n;
    vector<vector<int>> dp;
public:
    int maxValueOfCoins(vector<vector<int>>& P, int k) {
        n = P.size();
        dp.resize(n+1, vector<int>(k+1, 0));
        
        return solve(P, 0, k);
    }
    
    int solve(vector<vector<int>> &P, int i, int k) {
        if(i == n || k == 0) return 0;
        
        if(dp[i][k] > 0) return dp[i][k];
        
        int cur = 0, ans = solve(P, i+1, k);
        for(int j = 0; j < k && j < P[i].size(); j++) {
            cur += P[i][j];
            ans = max(ans, cur + solve(P, i+1, k - (j+1)));
        }
        return dp[i][k] = ans;
    }
};