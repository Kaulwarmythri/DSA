class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        bool flag = false;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1] && flag) count++;
            else if(nums[i]==nums[i-1]) flag = true, nums[i-count] = nums[i];
            else nums[i-count] = nums[i], flag = false;
        }
        return nums.size()-count;
    }
};

