class Solution {
    int n;
public:
    int longestPalindromeSubseq(string s) {
        string t = s; 
        reverse(t.begin(), t.end());
        
        n = s.size();
        return LCS(s, t);
    }
    
    int LCS(string s, string t) {
        vector<vector<int>> lcs(n+1, vector<int>(n+1, 1));
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0 || j == 0) 
                    lcs[i][j] = 0;
                else if(s[i-1] == t[j-1]) 
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                else
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
        return lcs[n][n];
    }
};