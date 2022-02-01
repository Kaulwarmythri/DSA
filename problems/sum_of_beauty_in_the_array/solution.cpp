class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), maxi = nums[0], beauty = 0;
        vector<int> mini(n, INT_MAX);
        mini[n-1] = nums[n-1];
        
        for(int i=n-2; i>=0; i--) mini[i] = min(nums[i], mini[i+1]);
        
        for(int i=1; i<n-1; i++){
            if(nums[i] > maxi && nums[i] < mini[i+1]) beauty += 2;
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1]) beauty++;
            maxi = max(maxi, nums[i]);
        }
        
        return beauty;
    }
};