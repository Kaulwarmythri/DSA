class Solution {
public:
    int search(vector<int>& nums, int X) {
        int n = nums.size(), l = 0, r = n-1;
        
        while(l <= r) {
            int mid = l + (r-l) / 2;
            
            if(nums[mid] == X) return mid;
            
            if(nums[l] <= nums[mid]) {
                if(X >= nums[l] && X <= nums[mid]) r = mid -1;
                
                else l = mid+1;
            } else {
                if(X >= nums[mid] && X <= nums[r]) l = mid+1;
                
                else r = mid-1;
            }
        }
        return -1;
    }
};