class Solution {
public:
    int n;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr_vec;
        sort(nums.begin(), nums.end());
        solve(nums, 0, curr_vec, ans);
        
        return ans;
        
    }
    
    void solve(vector<int> nums, int curr, vector<int> &curr_vec, vector<vector<int>> &ans){
        if(curr == n){
            ans.push_back(curr_vec);
            return;
        }
        
        curr_vec.push_back(nums[curr]);
        solve(nums, curr+1, curr_vec, ans);
        curr_vec.pop_back();
        
        int i = curr;
        while((i+1) < nums.size() && nums[curr] == nums[i+1]) i++;
        solve(nums, i+1, curr_vec, ans);
        
        
    }
};