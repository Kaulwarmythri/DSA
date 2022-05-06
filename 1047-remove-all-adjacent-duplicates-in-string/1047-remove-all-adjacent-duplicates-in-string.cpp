class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        
        for(auto ch : s) {
            if(!stk.empty() && stk.top() == ch) stk.pop();
            
            else stk.push(ch);
        }
        
        string ans = "";
        while(stk.size()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        
        return ans;
    }
};