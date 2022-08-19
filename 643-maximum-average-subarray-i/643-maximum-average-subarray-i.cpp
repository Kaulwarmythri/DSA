class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double curr = 0, sum = INT_MIN;
        
        for(int i=0; i<n; i++) {
            if(i < k) curr += nums[i];
            else {
                sum = max(sum, curr);
                curr += nums[i] - nums[i-k];
            }
        }
        sum = max(sum, curr);
        return sum / k;
    }
};