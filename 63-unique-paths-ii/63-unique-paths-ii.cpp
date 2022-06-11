class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size(), n = og[0].size();
        
        og[0][0] ^= 1;
        for(int i=1; i<m; i++) og[i][0] = !og[i][0] & og[i-1][0];
        
        for(int j=1; j<n; j++) og[0][j] = !og[0][j] & og[0][j-1];
        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                og[i][j] = (og[i][j]) ? 0 : og[i-1][j] + og[i][j-1];
            }
        }
        
        return og[m-1][n-1];
    }
};