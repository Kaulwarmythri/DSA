class Solution {
    int s;
public:
    int totalNQueens(int n) {
        s = n;
        vector<bool> cols(n), diags(2*n-1, false), anti_diags(2*n-1, false);
        
        return solve(0, cols, diags, anti_diags);
    }
    
    int solve(int row, vector<bool> &cols, vector<bool> &diags, vector<bool> &a_diags) {
        int count = 0;
        if(row == s) return 1;
        
        for(int j=0; j<s; j++) {
            if(!cols[j] && !diags[row+j] && !a_diags[row-j+s-1]) {
                cols[j] = diags[row+j] = a_diags[row-j+s-1] = true;
                
                count += solve(row+1, cols, diags, a_diags);
                
                cols[j] = diags[row+j] = a_diags[row-j+s-1] = false;
            }
        }
        return count;
    }
};