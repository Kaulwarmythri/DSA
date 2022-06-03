class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size(), max_reach = 0, curr_reach = 0;
        
        for(int i=0; i<n-1; i++) {
            if(i > curr_reach) return false;
            max_reach = nums[i]+i;
            curr_reach = max(curr_reach, max_reach);
        }
        return curr_reach >= n-1;
    }
};