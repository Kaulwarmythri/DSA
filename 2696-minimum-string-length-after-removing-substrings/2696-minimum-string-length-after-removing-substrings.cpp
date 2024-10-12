class Solution {
public:
    int minLength(string W) {
        stack<char> s;
        
        for(auto &c: W) {
            if(c == 'B') {
                if(s.size() && s.top() == 'A') 
                    s.pop();
                else
                    s.push(c);
            } else if(c == 'D') {
                if(s.size() && s.top() == 'C')
                    s.pop();
                else
                    s.push(c);
            } else {
                s.push(c);
            }
        }
        return s.size();
    }
};