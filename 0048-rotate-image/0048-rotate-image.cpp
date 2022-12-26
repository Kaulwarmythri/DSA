class Solution {
public:
    void rotate(vector<vector<int>>& M) {
        int n = M.size();
        
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                swap(M[i][j], M[j][i]);
            }
        }
        
        for(auto &x: M) reverse(x.begin(), x.end());
        
    }
};