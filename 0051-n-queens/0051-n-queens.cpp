class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> B(n, string(n, '.')); 
        solve(B, 0);
        
        return ans;
        
    }
    
    void solve(vector<string> &B, int row) {
        if(row == B.size()) {
            ans.push_back(B);
            return;
        }
        
        for(int col=0; col<B.size(); col++) {
            if(isSafe(B, row, col)) {
                B[row][col] = 'Q';
                
                solve(B, row+1);
                
                B[row][col] = '.';
            }
        }
    }
    
    bool isSafe(vector<string> B, int row, int col) {
        for(int i=0; i<B.size(); i++) {
            if(B[i][col] == 'Q') return false;
        }
        
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(B[i][j] == 'Q') return false;
        }
        
        for(int i=row-1, j=col+1; i>=0 && col<B.size(); i--, j++) {
            if(B[i][j] == 'Q') return false;
        }
        return true;
    }
       
};