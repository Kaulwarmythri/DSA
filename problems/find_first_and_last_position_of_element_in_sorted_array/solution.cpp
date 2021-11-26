class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1, -1};
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin()-1;
        
        if(l==nums.size() || nums[l] != target) return {-1, -1};
        
        return {l, r};
    }

    
};