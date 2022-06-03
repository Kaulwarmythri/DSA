class NumMatrix {
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> sum(m, vector<int>(n));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                sum[i][j] = matrix[i][j];
                
                if(i) sum[i][j] += sum[i-1][j];
                
                if(j) sum[i][j] += sum[i][j-1];
                
                if(i && j) sum[i][j] -= sum[i-1][j-1];
            }
        }
        mat = sum;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = mat[row2][col2];
        
        if(row1) ans -= mat[row1-1][col2];
        
        if(col1) ans -= mat[row2][col1-1]; 
        
        if(row1 && col1) ans += mat[row1-1][col1-1];
        
        return ans;
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */