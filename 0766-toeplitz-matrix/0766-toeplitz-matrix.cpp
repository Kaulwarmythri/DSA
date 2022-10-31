class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(M[i][j] != M[i-1][j-1]) 
                    return false;
            }
        }
        return true;
    }
};