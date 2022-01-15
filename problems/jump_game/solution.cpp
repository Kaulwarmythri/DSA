class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), max_range = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            max_range = max(max_range, nums[i]+i);
            if(max_range >= n-1) break;
            if(max_range == i) return false;
        }
        return true;
    }
};