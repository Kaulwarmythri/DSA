class NumMatrix {
public:
    vector<vector<int>> matrix;
    int m,n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> sum(m,vector<int>(n,0));
        //prefix sum matrix
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                sum[i][j] = matrix[i][j];
                if(i>0)
                    sum[i][j] += sum[i-1][j];
                if(j>0)
                    sum[i][j] += sum[i][j-1];
                if(i&&j)
                    sum[i][j] -= sum[i-1][j-1];
            }
        }
        this->matrix = sum;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = matrix[row2][col2];
        if(col1>0)
            ans -= matrix[row2][col1-1];
        if(row1>0)
            ans -= matrix[row1-1][col2];
        if(row1 && col1)
            ans += matrix[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */