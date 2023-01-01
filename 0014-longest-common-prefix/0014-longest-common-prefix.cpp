class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), i = 0;
        string ans = "";
        if(!n) return "";
        
        sort(strs.begin(), strs.end());
        
        string first = strs[0], last = strs[n-1];
        for(i=0; i<min(first.size(), last.size()); i++) {
            if(first[i] == last[i])
                ans += first[i];
            else break;
        }
        return ans;
        
    }
};