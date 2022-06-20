class Solution {
public:
    bool wordBreak(string s, vector<string>& words) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        
        dp[0] = true; //empty string
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++) {
                if(dp[j] && count(words.begin(), words.end(), s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};