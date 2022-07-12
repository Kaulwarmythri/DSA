class Solution {
    int n, sum = 0, mask;
public:
    bool makesquare(vector<int>& nums) {
        n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0); 
        if(n < 4 || sum % 4 != 0) return false;
        
        mask = (1<<n)-1;
        return solve(nums, sum/4, mask, 0, 0, 0);
    }
    
    bool solve(vector<int> &nums, int target, int mask, int curr, int i, int side) {
        if(side == 3) return 1;
        
        if(curr == target) return solve(nums, target, mask, 0, 0, side+1);
        
        for(int j=i; j<n; j++) {
            if(!(mask & (1<<j)) || curr + nums[j] > target) continue;
            
            mask &= ~(1<<j);
            if(solve(nums, target, mask, curr+nums[j], j+1, side)) return true;
            mask |= (1<<j);
        }
        return false;
    }
};