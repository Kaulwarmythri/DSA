class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int curMax = 0, maxi = 0;
            for (int k = 1; k <= K && i - k >= 0; k++) {
                curMax = max(curMax, A[i - k]);
                maxi = max(maxi, dp[i - k] + curMax * k);
            }
            dp[i] = maxi; 
        }
        return dp[n];
    }
};



//dp[i] -> max sum we can get from 0 to i-1 elements in A