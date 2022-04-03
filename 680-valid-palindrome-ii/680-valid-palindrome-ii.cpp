class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size(), cnt1 = 0, cnt2 = 0, l = 0, r = n-1;

        while(l < r) {
            if(s[l] == s[r]) l++, r--;
            else {
                cnt1++;
                r--;
            }
            if(cnt1 > 1) break;
        }
        
        l = 0, r = n-1;
        
        while(l < r) {
            if(s[l] == s[r]) l++, r--;
            else {
                cnt2++;
                l++;
            }
            if(cnt2 > 1) break;
        }
        
        if(cnt1 <= 1 || cnt2 <= 1) return true;
        
        return false;
    }
};