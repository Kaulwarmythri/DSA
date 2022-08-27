class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& A, int k) {
        int m = A.size(), n = A[0].size(), ans = INT_MIN;
        
        for(int i=0; i<m; i++) {
            for(int j=1; j<n; j++) {
                A[i][j] += A[i][j-1];
            }
        }
        
        for (int startCol = 0; startCol < n; ++startCol) {
            for (int endCol = startCol; endCol < n; ++endCol) {
                
                set<int> seen; seen.insert(0);
                
                int rowPrefSum = 0;
                
                for (int row = 0; row < m; ++row) {
                    rowPrefSum += A[row][endCol] - (startCol ? A[row][startCol-1] : 0);

                    auto it = seen.lower_bound(rowPrefSum - k);
                    
                    if (it != seen.end()) ans = max(ans, rowPrefSum - *it);
                    
                    seen.insert(rowPrefSum);
                }
                
                
            }
        }
        
        return ans;
    }
};