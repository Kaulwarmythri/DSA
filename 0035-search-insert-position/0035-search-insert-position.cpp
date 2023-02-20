class Solution {
public:
    int searchInsert(vector<int>& nums, int X) {
        int l = 0, r = nums.size() - 1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == X) return mid;
            else if(nums[mid] > X) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};