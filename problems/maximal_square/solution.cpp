class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxi = 0, prev;
        vector<int> dp(n+1, 0);
        for(int i = 0;i < m;i++) {
            int prev = 0;
            for(int j = 1;j <= n;j++) {
                int tmp = dp[j];
                if(matrix[i][j-1] == '1') dp[j] = 1 + min({prev, dp[j], dp[j-1]});
                else dp[j] = 0;
                prev = tmp;
                maxi = max(maxi, dp[j]);
            }
        }
        return maxi*maxi;
    }
};

