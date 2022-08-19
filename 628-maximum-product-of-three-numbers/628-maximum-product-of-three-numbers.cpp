class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int smallest, next_smallest;
        partial_sort(nums.begin(), nums.begin()+2, nums.end());
        
        smallest = nums[0], next_smallest = nums[1];
        
        partial_sort(nums.begin(), nums.begin()+3, nums.end(), greater<int>());
        
        return max(nums[0] * smallest * next_smallest, nums[0] * nums[1] *nums[2]);
    }
};