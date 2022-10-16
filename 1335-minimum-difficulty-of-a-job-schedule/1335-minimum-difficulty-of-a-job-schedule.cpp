class Solution {
    vector<vector<int>> dp;
    int n;
public:
    int minDifficulty(vector<int>& jd, int d) {
        n = jd.size();
        dp.resize(n+1, vector<int>(d+1, -1));
        
        int ans = solve(jd, 0, d);
        return ans == INT_MAX ? -1 : ans;
    }
    
    int solve(vector<int> &jd, int start, int d) {
        if(d == 0 && start == n) return 0;
        
        if(d == 0 || start == n) return INT_MAX;
        
        if(dp[start][d] != -1)
            return dp[start][d];
        
        int ans = INT_MAX, currmax = INT_MIN;
        for(int j=start; j<n; j++) {
            currmax = max(currmax, jd[j]);
            int sub = solve(jd, j+1, d-1);
            if(sub != INT_MAX) {
                ans = min(ans, currmax + sub);
            }
        }
        
        return dp[start][d] = ans;
    }
};