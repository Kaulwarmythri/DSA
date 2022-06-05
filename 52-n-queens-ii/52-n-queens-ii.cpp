class Solution {
    int s;
public:
    int totalNQueens(int n) {
        s = n;
        vector<bool> cols(n, false), diags(n, false), anti_diags(n, false);
        
        return solve(0, cols, diags, anti_diags);
        
    }
    
    int solve(int row, vector<bool> &cols, vector<bool> &diags, vector<bool> &anti_diags) {
        if(row >= s) {
            return 1;
        }
        
        int count = 0;
        
        for(int j=0; j<s; j++) {
            if(!cols[j] && !diags[row+j] && !anti_diags[row-j+s-1]) {
                
                cols[j] = diags[row+j] = anti_diags[row-j+s-1] = true;
                
                count += solve(row+1, cols, diags, anti_diags);
                
                cols[j] = diags[row+j] = anti_diags[row-j+s-1] = false;     
            }
        }
        return count;
    }
    
    
};