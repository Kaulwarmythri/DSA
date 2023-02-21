class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int idx = (mid & 1) ? mid - 1 : mid + 1;
            if(nums[mid] == nums[idx]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};