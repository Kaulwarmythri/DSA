class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(auto &c: t) m[c]++;
        
        int n = s.size(), l = 0, r = 0, min_len = INT_MAX, start = INT_MAX, count = 0;
        
        for(r = 0; r < n; r++) {
            if(m[s[r]] > 0) count++;
            m[s[r]]--;
            
            if(count == t.size()) {
                while(l < r && m[s[l]] < 0) m[s[l]]++, l++;
                if(min_len > r - l) min_len = r - (start = l) + 1;
                m[s[l++]]++;
                count--;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};