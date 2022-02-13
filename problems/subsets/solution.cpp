class Solution {
public:
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr_vec;
        solve(nums, 0, curr_vec, ans);
        return ans;
    }
    
    void solve(vector<int> nums, int curr, vector<int> &curr_vec, vector<vector<int>> &ans){
        if(curr == n){
            ans.push_back(curr_vec);
            return;
        }
        solve(nums, curr+1, curr_vec, ans);
        curr_vec.push_back(nums[curr]);
        solve(nums, curr+1, curr_vec, ans);
        curr_vec.pop_back();
    }
};