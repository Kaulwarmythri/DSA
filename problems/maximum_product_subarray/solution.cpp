class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0], maxi=nums[0], mini=nums[0];
        
        for(int i=1;i<nums.size();i++){
            int currMax = max({nums[i], nums[i]*mini, nums[i]*maxi});
            mini = min({nums[i], nums[i]*mini, nums[i]*maxi});
            maxi = currMax;
            ans=max(maxi, ans);
        }
        return ans;
    }
};