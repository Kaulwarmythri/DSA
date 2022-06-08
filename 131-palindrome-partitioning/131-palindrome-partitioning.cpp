class Solution {
    vector<string> buff;
    vector<vector<string>> ans;
    vector<vector<int>> dp;
    int n;
    
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        dp.resize(n, vector<int>(n, -1));
        
        solve(s, 0, buff, ans);
        return ans;
    }
    
    void solve(string s, int idx, vector<string> &buff, vector<vector<string>> &ans) {
        if(idx == n) {
            ans.push_back(buff);
            return;
        }
        
        for(int j=idx; j<n; j++) {
            if(check(s, idx, j)) {
                buff.push_back(s.substr(idx, j-idx+1));
                solve(s, j+1, buff, ans);
                buff.pop_back();
            }
        }
        
    }
    
    bool check(string str, int s, int e) {
        if(dp[s][e] != -1) return dp[s][e];
        
        while(s < e) {
            if(str[s] != str[e]) return dp[s][e] = 0; 
            s++; e--;
        }
        return dp[s][e] = 1;
        
    }
};
    