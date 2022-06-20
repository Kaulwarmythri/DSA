class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = nums[0], mini = nums[0], maxi = nums[0];
        
        for(int i=1;i<n;i++){
            int currMax = max({nums[i], nums[i]*mini, nums[i]*maxi});
            mini = min({nums[i], nums[i]*mini, nums[i]*maxi});
            maxi = currMax;
            ans=max(maxi, ans);
        }
        return ans;

    }
};