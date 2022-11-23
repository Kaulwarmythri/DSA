class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& B) {
        vector<set<int>> rows(9), cols(9), blocks(9);
        
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(B[i][j] == '.') 
                    continue;
                int n = B[i][j] - '0';
                if(rows[i].count(n) || cols[j].count(n) || blocks[i/3*3 + j/3].count(n))
                    return false;
                
                rows[i].insert(n);
                cols[j].insert(n);
                blocks[i/3*3 + j/3].insert(n);
            }
        }
        return true;
    }
};