class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int count = 0, l=0, r=0, limit = 1, maxLen = 0;
        while(r < n){
            if(nums[r] == 0) count++;
            while(count > limit){
                if(nums[l]==0) count--;
                l++;
            }
            maxLen = max(maxLen, r-l);
            r++;
        }
        return maxLen;
    }
};