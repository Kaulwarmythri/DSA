class Solution {
public:
    vector<int> dp;
    int m, t;
    bool play(int mask, int score){
        if(dp[mask]!=-1) return dp[mask];
        
        for(int i=0;i<m;i++){
            int new_mask = 1<<i;
            if((mask&new_mask)==0){
                if(score+i+1>=t || !(play(mask|new_mask, score+i+1))) return dp[mask]=true;
            }
        }
        return dp[mask]=false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        m=maxChoosableInteger, t=desiredTotal;
        if(m >= t) return true;
        if(m*(m+1)/2 < t) return false;
        if(m*(m+1)/2 == t) return m%2;
        dp.resize((1<<m), -1);
        return play(0, 0);
        
    }
};