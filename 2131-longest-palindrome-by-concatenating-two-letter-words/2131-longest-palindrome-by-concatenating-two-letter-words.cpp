class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> dp(26, vector<int>(26, 0));
        int ans = 0;
        for(auto &w: words) {
            int a = w[0] - 'a', b = w[1] - 'a';
            if(dp[b][a]) {
                ans += 4;
                dp[b][a]--;
            }
            else dp[a][b]++;
        }
        
        for(int i=0; i<26; i++) {
            if(dp[i][i]) {
                ans += 2;
                break;
            }
            
        }
        
        return ans;
    }
};