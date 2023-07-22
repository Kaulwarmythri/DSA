class Solution {
    int dirs[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}, {-2, 1}, {-1, 2}};
    double dp[26][26][1001] =  {[0 ... 25] = {[0 ... 25] = {[0 ... 100] = -1.0}}};
public:
    double knightProbability(int n, int k, int i, int j) {
        if(i < 0 || j < 0 || i >= n || j >= n) 
            return 0;
        
        if(k == 0)
            return 1;
        
        if(dp[i][j][k] != -1.0)
            return dp[i][j][k];
        
        double sum = 0;
        for(int p=0; p<8; p++) {
            sum += knightProbability(n, k-1, i+dirs[p][0], j+dirs[p][1]);
        }
        return dp[i][j][k] = sum / 8.0;
    }
};