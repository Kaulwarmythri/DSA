class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), len = 1, prev = 0, curr = 0;
        
        for(int i=1; i<n; i++) {
            curr = nums[i] - nums[i-1];
            if((curr > 0 && prev <= 0) || (curr < 0 && prev >= 0)) len++, prev = curr;
        }
        return len;
    }
};