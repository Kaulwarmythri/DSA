class Solution {
    int m, n;
public:
    bool exist(vector<vector<char>>& B, string word) {
        m = B.size(), n = B[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(B[i][j] == word[0] && solve(B, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool solve(vector<vector<char>> &B, int i, int j, string word, int idx) {
        if(idx == word.size()) return true;
        
        if(i < 0 || j < 0 || i >= m || j >= n || B[i][j] != word[idx]) return false;
        
        char c = B[i][j]; B[i][j] = '.';
        
        bool found = solve(B, i-1, j, word, idx+1) || solve(B, i, j-1, word, idx+1) || solve(B, i+1, j, word, idx+1) || solve(B, i, j+1, word, idx+1);
        
        B[i][j] = c;
        return found;
    }
};




