class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOps) {
        int n = nums.size(), l = 1, r = *max_element(nums.begin(), nums.end());
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            
            if(isPossible(nums, mid, maxOps))
                r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    bool isPossible(vector<int> &nums, int maxBalls, int maxOps) {
        int ops = 0;
        
        for(auto &x: nums) {
            ops += ceil (x / (double) maxBalls) - 1;
            
            if(ops > maxOps)
                return false;
        }
        return true;
    }
};