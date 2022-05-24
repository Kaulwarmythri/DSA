class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), MAX = 0;
        
        stack<int> stk;
        stk.push(-1);
        
        for(int i=0; i<n; i++) {
            if(s[i] == '(') stk.push(i);
            
            else { 
                stk.pop();
                if(!stk.empty()) MAX = max(MAX, i - stk.top());
                else stk.push(i);
            }
        }
        
        return MAX;
    }
};