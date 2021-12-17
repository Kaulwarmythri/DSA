class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxi = 0, prev;
        vector<int> dp(n, 0);
        for(int i=m-1;i>=0;i--){
            int prev = 0;
            for(int j=n-1;j>=0;j--){
                int temp = dp[j];
                if(i==m-1 || j==n-1 || matrix[i][j]=='0') dp[j] = matrix[i][j]-'0';
                else dp[j] = 1 + min({dp[j], dp[j+1], prev});
                prev = temp;
                
                maxi = max(maxi, dp[j]);
            }
        }
        return maxi*maxi;
    }
};

