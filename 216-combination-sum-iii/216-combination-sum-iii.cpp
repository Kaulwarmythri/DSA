class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, k, n, curr, ans);
        return ans;
    }
    
    void solve(int i, int k, int n, vector<int> &curr, vector<vector<int>> &ans){
        if(curr.size() == k) {
            if(n == 0) {
                ans.push_back(curr);
                return;
            }
        }
        
        for(int j=i; j<=9; j++) {
            if(n - j >= 0) {
                curr.push_back(j);
                solve(j+1, k, n-j, curr, ans);
                curr.pop_back();
            }
        }
    }
};