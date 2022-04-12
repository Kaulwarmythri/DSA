class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int living = countNeighbours(board, i, j);
                
                if(board[i][j] & 1 && (living == 2 || living == 3)) 
                    board[i][j] += 2;
                
                else if(!(board[i][j] & 1) && (living == 3))
                    board[i][j] += 2;
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] & 2) board[i][j] = 1;
                
                else board[i][j] = 0;
            }
        }
    }
    
    int countNeighbours(vector<vector<int>> board, int i, int j) {
        bool up = i > 0, down = i < board.size()-1;
        
        bool left = j > 0, right = j < board[0].size()-1;
        
        int count = 0;
        
        if(up) {
            count += board[i-1][j] & 1;
            if(left) count += board[i-1][j-1] & 1;
            
            if(right) count += board[i-1][j+1] & 1;
        }
        if(down) {
            count += board[i+1][j] & 1;
            if(left) count += board[i+1][j-1] & 1;
            
            if(right) count += board[i+1][j+1] & 1;
        }
        if(left) count += board[i][j-1] & 1;
        
        if(right) count += board[i][j+1] & 1;
        
        return count;
        
    }    
};

