class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while(l < r) {
            if(nums[l] % 2 && !(nums[r] % 2)) swap(nums[l], nums[r]);
            
            else if(!(nums[l] % 2)) l++;
            
            else if(nums[r] % 2) r--;
        }
        
        return nums;
    }
};