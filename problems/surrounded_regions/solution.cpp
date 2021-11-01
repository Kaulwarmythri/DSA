class Solution {
public:
    int row,col;
    void solve(vector<vector<char>>& board) {
        row=board.size(),col=board[0].size();
        for(int i=0;i<row;i++){
            check(board,i,0);
            check(board,i,col-1);
        }
        for(int i=0;i<col;i++){
            check(board,0,i);
            check(board,row-1,i);
        }
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(board[i][j]=='O')board[i][j]='X';
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(board[i][j]=='E')board[i][j]='O';
        
    }
    void check(vector<vector<char>>& board,int i,int j){
        if(board[i][j]=='O'){
            board[i][j]='E';
            if(i+1<row)check(board,i+1,j);   
            //'coz this isn't surrounded by X's on all sides
            if(j+1<col)check(board,i,j+1);
            if(i-1>=0)check(board,i-1,j);
            if(j-1>=0)check(board,i,j-1);
        }
    }
};