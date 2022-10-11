class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(), first = nums[0], sec = INT_MAX;
        
        for(int i=0; i<n; i++) {
            if(nums[i] <= first)
                first = nums[i];
            else if(nums[i] <= sec)
                sec = nums[i];
            else 
                return true;
        }
        return false;
    }
};