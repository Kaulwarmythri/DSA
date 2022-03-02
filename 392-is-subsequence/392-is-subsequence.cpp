class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = t.size(), n = s.size(), i=0, j=0;
        while(i < n && j < m){
            if(s[i] == t[j]) i++, j++;
            else j++;
        }
        return i==n;
    }
};