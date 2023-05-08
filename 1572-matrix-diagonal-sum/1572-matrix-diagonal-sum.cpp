class Solution {
public:
    int diagonalSum(vector<vector<int>>& M) {
        int n = M.size(), sum = 0;
        
        for(int i=0; i<n; i++) {
            sum += (i == n-i-1) ? M[i][i] : M[i][i] + M[i][n-i-1];
        }
        return sum;
    }
};