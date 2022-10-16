class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size(), maxi = 0;
        vector<int> dp(n, 0);
        
        for(int i=m-1; i>=0; i--) {
            int dia = 0;
            for(int j=n-1; j>=0; j--) {
                int temp = dp[j];
                if(i == m-1 || j == n-1 || mat[i][j] == '0') dp[j] = mat[i][j] - '0';
                else {
                    dp[j] = 1 + min({dp[j], dp[j+1], dia});
                }
                maxi = max(dp[j], maxi);
                dia = temp;
            }
        }
        return maxi * maxi;
    }
};

