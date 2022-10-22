class Solution {
    int dir[8][2] = {{-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}, {2, 1}, {1, 2}, {1, -2}, {2, -1}};
    double dp[26][26][1001] =  {[0 ... 25] = {[0 ... 25] = {[0 ... 100] = -1.0}}};
public:
    double knightProbability(int n, int k, int i, int j) {
        if(i < 0 || j < 0 || i >= n || j >= n) return 0.0;
        
        if(k == 0) return 1.0;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        double ans = 0.0;
        for(int p=0; p<8; p++) {
            ans += knightProbability(n, k-1, i+dir[p][0], j+dir[p][1]);
        }
        return dp[i][j][k] = ans / 8.0;
    }
};
