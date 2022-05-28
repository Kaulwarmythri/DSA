class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xOR = 0, n = nums.size();
        
        for(int i=0; i<n; i++) xOR ^= nums[i];
        
        for(int i=0; i<=n; i++) xOR ^= i;
        
        return xOR;
    }
};