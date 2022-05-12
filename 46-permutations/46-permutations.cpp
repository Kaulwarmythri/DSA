class Solution {
    int n;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        
        solve(nums, 0, ans);
        
        return ans;
    }
    
    void solve(vector<int> &nums, int i, vector<vector<int>> &ans) {
        if(i == n) {
            ans.push_back(nums);
            return;
        }
        
        for(int j=i; j<n; j++) {
            swap(nums[i], nums[j]);
            solve(nums, i+1, ans);
            swap(nums[i], nums[j]);
        }
    }
};