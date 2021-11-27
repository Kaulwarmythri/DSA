class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::partial_sort(nums.begin(), nums.begin()+2, nums.end());
        int smallest = nums[0], next_smallest = nums[1];
        
        std::partial_sort(nums.begin(), nums.begin()+3, nums.end(), greater<int>());
        
        return max(smallest*next_smallest*nums[0], nums[0]*nums[1]*nums[2]);
    }
};