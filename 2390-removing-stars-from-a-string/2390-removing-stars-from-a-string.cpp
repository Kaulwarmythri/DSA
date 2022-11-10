class Solution {
public:
    string removeStars(string str) {
        stack<char> s;
        
        for(auto &c: str) {
            if(c != '*') s.push(c);
            else s.pop();
        } 
        
        string ans = "";
        while(!s.empty()) {
            ans.push_back(s.top()); s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};