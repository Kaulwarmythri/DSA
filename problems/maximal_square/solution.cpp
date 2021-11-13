class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        int maxi=0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1||j==n-1) dp[i][j]=matrix[i][j]-'0';
                else{
                    if(matrix[i][j]=='0') dp[i][j]=0;
                    else dp[i][j]=1+min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]});
                }
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi*maxi;
    }
};

