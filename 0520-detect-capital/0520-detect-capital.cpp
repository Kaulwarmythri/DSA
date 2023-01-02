class Solution {
public:
    bool detectCapitalUse(string s) {
        int n = s.size();
        
        for(int i=1; i<n; i++) {
            if((islower(s[0]) && isupper(s[i])) || (isupper(s[1]) != isupper(s[i])))
                return false;
        }
        return true;
    }
};