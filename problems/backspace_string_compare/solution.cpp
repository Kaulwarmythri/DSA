class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, ts;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(ss.empty()) continue;
                ss.pop();
            }
            else ss.push(s[i]);
        }
        for(int j=0;j<t.size();j++){
            if(t[j]=='#'){
                if(ts.empty()) continue;
                ts.pop();
            }
            else ts.push(t[j]);
        }
        return ss==ts;
    }
    
};