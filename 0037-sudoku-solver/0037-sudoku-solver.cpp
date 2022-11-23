class Solution {
public:
    void solveSudoku(vector<vector<char>>& B) {
        solve(B, 0, 0);
    }
    
    bool solve(vector<vector<char>> &B, int i, int j) {
        if(i == 9) return true;
        if(j == 9) return solve(B, i+1, 0);
        if(B[i][j] != '.') return solve(B, i, j+1);
        
        for(char c='1'; c<='9'; c++) {
            if(valid(B, i, j, c)) {
                B[i][j] = c;
                if(solve(B, i, j+1)) return true;
                B[i][j] = '.';
            }
        }
        return false;
    }
    
    bool valid(vector<vector<char>> &B, int i, int j, char c) {
        for(int k=0; k<9; k++) {
            if(B[i][k] == c) return false;
            if(B[k][j] == c) return false;
            if(B[i - i%3 + k/3][j - j%3 + k%3] == c) return false;
        }
        return true;
    }
};

