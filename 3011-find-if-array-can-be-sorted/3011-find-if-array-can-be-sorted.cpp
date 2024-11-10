class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size(), cur_min = nums[0], cur_max = nums[0], prev_max = INT_MIN;
        
        for(int i=0; i<n; i++) {
            if(__builtin_popcount(nums[i]) == __builtin_popcount(cur_min)) {
                cur_min = min(cur_min, nums[i]);
                cur_max = max(cur_max, nums[i]);
            } else {
                if(cur_min < prev_max) 
                    return false;
                prev_max = cur_max;
                cur_min = nums[i];
                cur_max = nums[i];
            }   
        }
        return cur_min < prev_max ? false : true;
    }
};


//https://www.youtube.com/watch?v=OpOPUeGFjxE