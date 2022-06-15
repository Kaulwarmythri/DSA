class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        sort(words.begin(), words.end(), [](string a, string b)-> bool {
            return a.size() < b.size();
        });
        
        vector<int> dp(n, 1);
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(words[j].size()+1 == words[i].size() && check(words[j], words[i]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    
    bool check(string a, string b) {
        int m = a.size(), n = b.size(), missing = 0, i=0, j=0;
        
        while(i < m && j < n) {
            if(a[i] == b[j]) i++, j++;
            else {
                if(!missing) missing = 1, j++;
                else return false;
            }
        }
        return true;
    }
};