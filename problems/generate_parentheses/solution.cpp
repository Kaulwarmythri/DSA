class Solution {
vector<string>ans;
public:
    vector<string> generateParenthesis(int n) {
        string s="";
        validParenthesis(n, s, 0, 0);
        return ans;
    }
    void validParenthesis(int n, string s, int open, int close){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            validParenthesis(n, s+"(", open+1, close);
        }
        if(close<open){
            validParenthesis(n, s+")", open, close+1);
        }
    }
};
