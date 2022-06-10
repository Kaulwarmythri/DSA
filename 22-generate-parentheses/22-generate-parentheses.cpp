class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n, 0, 0);
        
        return ans;
    }
    
    void solve(string curr, int n, int open, int close) {
        if(open == n && close == n) {
            ans.push_back(curr);
            return;
        }
        
        if(open < n) solve(curr + '(', n, open+1, close);
        
        if(close < open) solve(curr + ')', n, open, close+1);
    }
};