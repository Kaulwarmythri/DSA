class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                int smallest = matrix[i-1][j];
                
                if(j>0) smallest = min(smallest, matrix[i-1][j-1]);
                if(j+1<matrix.size()) smallest = min(smallest, matrix[i-1][j+1]);
                matrix[i][j]+=smallest;
            }
        }
        return *min_element(matrix[matrix.size()-1].begin(), matrix[matrix.size()-1].end());
    }
};