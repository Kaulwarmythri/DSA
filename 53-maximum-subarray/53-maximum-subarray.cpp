class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = 0, maxi = INT_MIN;
        
        for(int i=0; i<n; i++) {
            sum = max(nums[i], nums[i]+sum);
            maxi = max(maxi, sum);
            
        }
        return maxi;
    }
};