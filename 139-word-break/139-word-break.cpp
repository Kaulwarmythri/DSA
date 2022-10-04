class Solution {
    int n;
    vector<int> dp;
public:
    bool wordBreak(string s, vector<string>& words) {
        n = s.size();
        dp.resize(n+1, -1);
        return solve(s, words, 0);
    }
    
    bool solve(string s, vector<string> &words, int i) {
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];
        
        for(int j=i; j<n; j++) {
            if(count(words.begin(), words.end(), s.substr(i, j-i+1)) && solve(s, words, j+1)) 
                return dp[i] = 1;
        }
        return dp[i] = 0;
    }
};