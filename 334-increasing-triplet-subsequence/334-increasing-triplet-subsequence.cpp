class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(), mini = nums[0], first = mini, sec = INT_MAX, third = INT_MAX;
        
        for(int i=1; i<n; i++) {
            if(nums[i] == mini) 
                continue;
            else if(nums[i] < mini) 
                mini = nums[i];
            else if(nums[i] < sec) {
                sec = nums[i];
                first = mini;
            } else if(nums[i] > sec) {
                return true;
            }
        }
        return false;
    }
};