class Solution {
    int s;
public:
    int totalNQueens(int n) {
        s = n;
        vector<bool> cols(n, 0), diags(2*n+1, 0), anti_diags(2*n+1, 0);
        
        return solve(0, cols, diags, anti_diags);
    }
    
    int solve(int row, vector<bool> &cols, vector<bool> &diags, vector<bool> &anti_diags) {
        if(row >= s) 
            return 1;
        
        int count = 0;
        for(int col=0; col<s; col++) {
            if(!cols[col] && !diags[row+col] && !anti_diags[row-col+s-1]) {
                cols[col] = diags[row+col] = anti_diags[row-col+s-1] = true;
                count += solve(row+1, cols, diags, anti_diags);
                cols[col] = diags[row+col] = anti_diags[row-col+s-1] = false;
            } 
        }
        return count;
    }
};
 
//n - cols   2*n-1 - diags    2*n-1 anti-diags
//   |             /                 \              => directions
//  col          row+col        row-col+n-1
