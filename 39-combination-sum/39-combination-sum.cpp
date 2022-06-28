class Solution {
    vector<vector<int>> ans;
    vector<int> buff;
    int n;
public:
    vector<vector<int>> combinationSum(vector<int>& c, int X) {
        n = c.size();
        sort(c.begin(), c.end());
        solve(c, 0, X, buff);
        
        return ans;
    }
    
    void solve(vector<int>& c, int i, int X, vector<int> &buff) {
        if(i == n) return;
        if(X == 0) {
            ans.push_back(buff);
            return;
        }
        
        for(int j=i; j<n; j++) {
            if(c[j] <= X) {
                buff.push_back(c[j]);
                solve(c, j, X-c[j], buff);
                buff.pop_back();
            }
        }
    }
};