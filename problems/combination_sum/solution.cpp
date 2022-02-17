class Solution {
    int n;
public:
    vector<vector<int>> combinationSum(vector<int>& C, int X) {
        n = C.size();
        sort(C.begin(), C.end());
        vector<int> curr; 
        vector<vector<int>> ans;
        solve(C, 0, curr, ans, X);
        return ans;
    }
    
    void solve(vector<int> &C, int i, vector<int> &curr, vector<vector<int>> &ans, int X){
        if(X == 0){
            ans.push_back(curr);
            return;
        }
        while(i < n && X - C[i] >= 0){
            curr.push_back(C[i]);
            solve(C, i, curr, ans, X-C[i]);
            curr.pop_back();
            i++;
        }
    }
};