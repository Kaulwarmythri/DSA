class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int> stk;
        
        for(int i=0; i<n; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') stk.push(s[i]);
            
            else {
                if(s[i] == ')') {
                    if(stk.empty() || stk.top() != '(') return false;
                    else stk.pop();
                }
                else if(s[i] == '}') {
                    if(stk.empty() || stk.top() != '{') return false;
                    else stk.pop();
                }
                else {
                    if(stk.empty() || stk.top() != '[') return false;
                    else stk.pop();
                }
            }
        }
        return stk.empty();
    }
};