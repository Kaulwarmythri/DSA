class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, ts;
        
        for(auto sc : s) {
            if(sc == '#') {
                if(!ss.empty()) ss.pop();
            }
            else ss.push(sc);
        }
        
        for(auto tc : t) {
            if(tc == '#') {
                if(!ts.empty()) ts.pop();
            }
            else ts.push(tc);
        }
        
        if(ss == ts) return true;
        
        return false;
    }
};