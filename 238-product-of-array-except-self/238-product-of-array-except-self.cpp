class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), left = 1, right = 1;
        vector<int> arr(n, 1);
        
        for(int i=0; i<n; i++) {
            arr[i] *= left;
            arr[n-i-1] *= right;
            left *= nums[i];
            right *= nums[n-i-1];
        }
        return arr;
    }
};