class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0, count = 0;
        
        for(int i=2; i<n; i++) {
            if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2]))
                count++;
            else 
                count = 0;
            
            ans += count;     //that subarray + the previous ones too
        }
        return ans;
    }
};