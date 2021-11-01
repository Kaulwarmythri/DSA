class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), max_range=0;
        for(int i=0;i<n;i++){
            max_range = max(max_range, nums[i]+i);
            if(max_range >= n-1) break;
            if(max_range == i) return false;
        }
        return true;
    }
};