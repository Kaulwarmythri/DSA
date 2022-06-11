class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0) - x;
        
        int n = nums.size(), l = 0, r = 0, curr = 0, len = 0;
        
        if(sum == 0) return n;
        
        while(l <= r) {
            if(curr < sum) {
                if(r < n) curr += nums[r++];
                else break;
            } else if(curr > sum) {
                curr -= nums[l++];
            } else {
                len = max(len, r-l);
                curr -= nums[l++];
            }
        }
        if(curr == sum) len = max(len, r-l);
        
        if(len == 0) return -1;
        return n - len;
    }
};