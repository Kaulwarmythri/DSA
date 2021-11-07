class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
         if(nums.size() < 3) return 0;
        int res=0;
        for(int i=2, count=0; i<nums.size(); i++){
            if(nums[i-2]-nums[i-1]==nums[i-1]-nums[i]) count++;
            else count=0;
            
            res+=count;
        }
        return res;
    }
};