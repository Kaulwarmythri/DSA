class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int X) {
        int m = A.size(), n = A[0].size(), ans = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=1; j<n; j++)  A[i][j] += A[i][j-1];
        }
        
        for(int colStart = 0; colStart < n; colStart++) {
            for(int colEnd = colStart; colEnd < n; colEnd++) {
                
                for(int rowStart = 0; rowStart < m; rowStart++) {
                    int sum = 0;
                    for(int rowEnd = rowStart; rowEnd < m; rowEnd++) {
                        sum += A[rowEnd][colEnd] - (colStart ? A[rowEnd][colStart-1] : 0);
                        if(sum == X) ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};
