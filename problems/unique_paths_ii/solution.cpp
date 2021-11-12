class Solution {
public:
 int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if(m>0)
        {
            int n=obstacleGrid[0].size();
            vector<vector<long int >> table(m,vector<long int> (n,-1));
        
            for(int i=m-1;i>=0;i--)
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(obstacleGrid[i][j]==1)
                        table[i][j]=0;
                    else if(i==m-1 && j==n-1)
                        table[i][j]=1;
                    else if(i==m-1)
                        table[i][j]=table[i][j+1];
                    else if(j==n-1)
                        table[i][j]=table[i+1][j];
                    else
                        table[i][j]=table[i+1][j]+table[i][j+1];
                }
            }
            return table[0][0];
        
        }
        return 0;

    }
};