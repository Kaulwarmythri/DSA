class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, "");
        return ans;
    }
    
    void solve(int n, int open, int close, string cur) {
        if(open == n && close == n) {
            ans.push_back(cur);
            return;
        }
        
        if(open < n)
            solve(n, open + 1, close, cur + '(');
        if(close < open)
            solve(n, open, close + 1, cur + ')');
    }
};