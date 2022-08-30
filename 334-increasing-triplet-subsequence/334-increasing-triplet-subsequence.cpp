class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(), mini = 0, maxi = n-1;
        vector<int> smaller(n, -1), greater(n, -1);
        
        for(int i=1; i<n; i++) {
            if(nums[i] <= nums[mini]) {
                mini = i;
            } else {
                smaller[i] = mini;
            }
        }
        
        for(int i=n-2; i>=0; i--) {
            if(nums[i] >= nums[maxi]) {
                maxi = i;
            } else {
                greater[i] = maxi;
            }
        }
        
        for(int i=0; i<n; i++) if(smaller[i] != -1 && greater[i] != -1) return true;
        
        return false;
    }
};