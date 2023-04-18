class Solution {
public:
    string mergeAlternately(string s, string t) {
        int m = s.size(), n = t.size(), i = 0, j = 0;
        
        string ans = "";
        while(i < m && j < n) {
            ans += s[i++];
            ans += t[j++];
        }
        
        while(i < m) ans += s[i++];
        while(j < n) ans += t[j++];
        
        return ans;
    }
};