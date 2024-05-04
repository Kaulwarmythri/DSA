class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.size(), ans = 0;
        
        stack<int> s; s.push(-1);
        
        for(int i=0; i<n; i++) {
            if(str[i] == '(') s.push(i);
            else {
                s.pop();
                if(s.empty())
                    s.push(i);
                else
                    ans = max(ans, i - s.top());
            }
        }
        return ans;
    }
};

