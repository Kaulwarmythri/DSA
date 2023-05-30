class Solution {
    int dp[102][102];
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0); 
        cuts.push_back(n);
        
        sort(cuts.begin(), cuts.end());
        
        memset(dp, -1, sizeof(dp));
        return solve(cuts, 0, cuts.size()-1);
    }
    
    int solve(vector<int> &cuts, int i, int j) {
        if(j - i < 2) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = INT_MAX;
        for(int k=i+1; k<=j; k++) {
            dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + solve(cuts, i, k) + solve(cuts, k, j));
        }
        return dp[i][j];
    }
};