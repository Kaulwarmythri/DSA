class Solution {
    int n;
    vector<int> dp;
public:
    bool wordBreak(string s, vector<string>& W) {
        n = s.size();
        unordered_set<string> words(W.begin(), W.end());
        
        dp.resize(n+1, -1);
        
        return solve(words, s, 0);
    }
    
    int solve(unordered_set<string> &words, string s, int i) {
        if(i == n) 
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        for(int j=i; j<n; j++) {
            if(words.find(s.substr(i, j-i+1)) != words.end() && solve(words, s, j+1))
                return dp[i] = 1;
        }
        return dp[i] = 0;
    }
};