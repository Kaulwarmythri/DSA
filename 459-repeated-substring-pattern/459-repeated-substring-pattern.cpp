class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1, j = 0, n = s.size();
        vector<int> lps(n, 0);
        
        while(i < n) {
            if(s[i] == s[j]) {
                lps[i++] = ++j;
            } else {
                if(j == 0) lps[i++] = 0;
                else j = lps[j - 1];
            }
        }
        
        return lps[n-1] && (lps[n-1] % (n - lps[n-1]) == 0);
    }
};
