class Solution {
public:
    string convert(string s, int rows) {
        if(rows == 1) return s;
        
        vector<string> v(min(rows, int(s.size())), "");
        int dir = -1, idx = 0;
        
        for(int i=0; i<s.size(); i++) {
            v[idx] += s[i];
            idx += dir == -1 ? 1 : -1;
            if(idx == 0 || idx == rows - 1) dir = -dir;
        }
        string ans = "";
        for(auto &x: v) ans += x;
        
        return ans;
    }
};
