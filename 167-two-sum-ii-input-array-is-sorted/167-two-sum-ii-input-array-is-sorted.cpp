class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size(), l = 0, r = n-1;
        
        while(l < r) {
            if(nums[l] + nums[r] == target) return {l+1, r+1};
            else if(nums[l] + nums[r] > target) r--;
            else l++;
        }
        
        return ans;
    }
};