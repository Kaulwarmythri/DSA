class Solution {
public:
    bool isValid(string s) {
        map<char, char> m;
        m.insert({')', '('});
        m.insert({'}', '{'});
        m.insert({']', '['});
        
        int n = s.size();
        stack<int> stk;
        
        for(int i=0; i<n; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') stk.push(s[i]);
            
            else {
                if(stk.empty() || stk.top() != m[s[i]]) return false;
                else stk.pop();
            }
        }
        return stk.empty();
    }
};