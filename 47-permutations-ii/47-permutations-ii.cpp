class Solution {
    int n;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        set<vector<int>> ans;
        solve(nums, 0, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void solve(vector<int> &nums, int i, set<vector<int>> &ans){
        if(i==nums.size()){
            ans.insert(nums);
            return;
        }
        
        for(int j=i; j<n; j++){
            swap(nums[i], nums[j]);
            solve(nums, i+1, ans);
            swap(nums[i], nums[j]);
        }
    }
};