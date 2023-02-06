class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int len = nums.size();
        
        for(int i=n; i<len; i++) 
            nums[i] = nums[i] * 1023 + nums[i - n];
        
        int idx = 0;
        for(int i=n; i<len; i++, idx+=2) {
            nums[idx] = nums[i] % 1023;
            nums[idx + 1] = nums[i] / 1023;
        }
        return nums;
    }
};
