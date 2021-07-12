class Solution {
public:
    bool isValid(string s) {
        
        map<char, char> m;
        m.insert(make_pair(')', '('));
        m.insert(make_pair(']', '['));
        m.insert(make_pair('}', '{'));
        
        stack<char> paren;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                paren.push(s[i]);
            }else if(s[i]==')'||s[i]==']'||s[i]=='}'){
                
                if(paren.empty()||paren.top() != m[s[i]]){return false;}
                else{paren.pop();}
            }
        }
        
        return paren.empty();
        
    }
};