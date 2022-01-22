class Solution {
    bool dp[100001] = {false};
public:
    bool winnerSquareGame(int n){
        if(n==0) return false;
        
        if(dp[n]) return dp[n];
        
        bool winner = false;
        for(int i=1; i*i <= n; i++){
            if(!winnerSquareGame(n - i*i)){
                winner = true;
                break;
            }   
        }
        return dp[n] = winner;
    }
};


