class Solution {
    vector<vector<int>> ans;
    int n;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        
        solve(nums, 0);
        
        return ans;
    }
    
    void solve(vector<int> &nums, int i) {
        if(i == n) {
            ans.push_back(nums);
            return;
        }
        
        for(int j=i; j<n; j++) {
            swap(nums[i], nums[j]);
            solve(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
};