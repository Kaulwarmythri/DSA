class Solution {
public:
    int minSubArrayLen(int X, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, sum = 0, len = INT_MAX;
         
        while(r < n) {
            sum += nums[r++];
            
            while(sum >= X) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};