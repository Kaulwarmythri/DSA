class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, l = 0, r = 0, count = 0;
        
        while(r < n) {
            if(!nums[r]) count++;
            
            while(count > k) {
                if(!nums[l]) count--;
                l++;
            }
            ans = max(ans, r++ - l + 1);
        }
        return ans;
    }
};