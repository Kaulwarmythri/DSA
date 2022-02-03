class Solution {
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b  = temp;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size(), k=4;
        while(k){
            for(int i=0; i<n; i++){
                for(int j=i; j<n; j++) swap(&mat[i][j], &mat[j][i]);
            }
            for(auto &x : mat) reverse(x.begin(), x.end());
            if(mat == target) return true;
            else k--;
        }
        return false;
    }
};