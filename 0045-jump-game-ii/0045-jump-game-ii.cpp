class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), max_reach = 0, curr_reach = 0, jumps = 0;
        
        for(int i=0; i<n-1; i++) {
            max_reach = max(nums[i] + i, max_reach);
            
            if(curr_reach == i) {
                curr_reach = max_reach;
                jumps++;
            }
        }
        return jumps;
    }
};