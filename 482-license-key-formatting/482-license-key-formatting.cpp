class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        for(auto i=s.rbegin(); i < s.rend(); i++) {
            if(*i != '-') {
                if(ans.size() % (k+1) == k)
                    ans += '-';
                ans += toupper(*i);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};