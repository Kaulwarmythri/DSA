class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& G) {
        int n = G.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));
        
        auto solve = [&G](int row, int col) {
            int maxi = G[row][col];
            
            for(int i=row; i<row+3; i++) {
                for(int j=col; j<col+3; j++) {
                    maxi = max(maxi, G[i][j]);
                }
            }
            
            return maxi;
        };
        
        for(int i=0; i<n-2; i++) {
            for(int j=0; j<n-2; j++) {
                ans[i][j] = solve(i, j);
            }
        }
        return ans;
    }
};