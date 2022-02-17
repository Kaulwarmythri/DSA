class Solution {
public:
    int n;
    vector<vector<int>> combinationSum2(vector<int>& C, int X) {
        n = C.size();
        sort(C.begin(), C.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(C, 0, curr, ans, X);
        return ans;
    }
    void solve(vector<int> &C, int i, vector<int> &curr, vector<vector<int>> &ans, int X){
        if(X == 0){
            ans.push_back(curr);
            return;
        }
        for(int j=i; j<n; j++){
            if(X - C[j] >= 0){
            if(j > i && C[j]==C[j-1]) continue;
            curr.push_back(C[j]);
            solve(C, j+1, curr, ans, X-C[j]);
            curr.pop_back();
            }
        }
    } 
};