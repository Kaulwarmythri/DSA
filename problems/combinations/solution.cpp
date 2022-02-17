class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, n, k, curr, ans);
        return ans;
        
    }
    
    void solve(int num, int n, int k, vector<int> &curr, vector<vector<int>> &ans){
        if(k==0){
            ans.push_back(curr);
            return;
        }
        for(int i=num; i<=n; i++){
            curr.push_back(i);
            solve(i+1, n, k-1, curr, ans);
            curr.pop_back();
        }
    }
};