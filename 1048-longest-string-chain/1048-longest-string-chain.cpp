class Solution {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),compare);
        for(int i = 1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(words[i].length()-words[j].length()==1 && lcs(words[i],words[j])==words[j].length() && dp[i]<dp[j]+1)
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    
    int lcs(string a, string b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else {
                    dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
};