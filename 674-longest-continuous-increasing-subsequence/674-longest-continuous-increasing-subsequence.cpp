class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), ans = 0, longest = 0;
        
        for(int i=0; i<n; i++) {
            if(i == 0 || nums[i] > nums[i-1]) ans = max(ans, ++longest);
            else longest = 1;
        }
        return ans;
    }
};