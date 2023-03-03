class Solution {
    int m, n;
public:
    int strStr(string s, string t) {
        m = s.size(); n = t.size();
        
        vector<int> lps(n, 0);
        if(!n) return 0;
        
        preprocess(t, lps);
        
        int i=0, j = 0;
        
        while(i < m && j < n) {
            if(s[i] == t[j]) i++, j++;
            
            if(j == n) return i - j;
            
            if(i < m && s[i] != t[j]) {
                if(!j) i++;
                else j = lps[j-1];
            }
        }
        return -1;
        
    }
    
    void preprocess(string t, vector<int> &lps) {
        int i = 1, j = 0;
        while(i < n) {
            if(t[i] == t[j]) lps[i++] = ++j;
            else {
                if(!j) i++;
                else j = lps[j-1];
            }
        }
    }
};