class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int X) {
        vector<int> ans(2, -1);
        
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] > X)
                r = mid-1;
            else if(nums[mid] < X)
                l = mid+1;
            else {
                if(mid == l || nums[mid] != nums[mid-1]) {
                    ans[0] = mid;
                    break;
                } else {
                    r = mid-1;
                }
            }
        }
        
        r = nums.size()-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] > X) 
                r = mid-1;
            else if(nums[mid] < X)
                l = mid+1;
            else {
                if(mid == r || nums[mid] != nums[mid+1]) {
                    ans[1] = mid;
                    break;
                } else {
                    l = mid+1; 
                    ans[1] = mid+1;
                }
            }
        }
        
        return ans;
    }
};