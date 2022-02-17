class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int X) {
        set<vector<int>> ans;
        vector<int> curr;
        solve(1, k, X, curr, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void solve(int i, int k, int X, vector<int> &curr, set<vector<int>> &ans){
        if(X == 0 && k==0){
            ans.insert(curr);
            return;
        }
        
        for(int j=i; j<=9; j++){
            if(X - j >= 0){
                curr.push_back(i);
                solve(j+1, k-1, X-i, curr, ans);
                curr.pop_back();
                solve(j+1, k, X, curr, ans);
            }
        }
    }
};