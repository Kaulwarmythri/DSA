class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int max_reach=0, curr_reach=0, jumps=0;
        
        for(int i=0;i<nums.size()-1;i++){
            max_reach = max(max_reach, nums[i]+i);
            if(i==curr_reach) curr_reach = max_reach, jumps++;   
            if(curr_reach >= nums.size()) break;
        }
        return jumps;
    }
};