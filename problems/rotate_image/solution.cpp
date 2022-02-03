class Solution {
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(&matrix[i][j], &matrix[j][i]);
            }
        }
        
        for(auto &x : matrix) reverse(x.begin(), x.end());
    }
};