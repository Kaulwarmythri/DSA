class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> s;
        
        for(auto &c: str) {
            if(s.size() && s.top() == c) s.pop();
            else s.push(c);
        }
        
        string ans = "";
        while(!s.empty()) {
            ans = s.top() + ans;
            s.pop();
        }
        return ans;
    }
};