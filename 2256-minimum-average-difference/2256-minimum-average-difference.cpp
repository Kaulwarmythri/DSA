class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), mini = INT_MAX, idx = 0;
        
        long long pre[n];  pre[0]=nums[0];

        for(int i=1; i<n; i++)    
            pre[i] = pre[i-1] + nums[i];

        for(int i=1; i<n; i++) {
            int diff = abs(pre[i-1] / i - (pre[n-1] - pre[i-1]) / (n - i));
            if(mini > diff) {
                mini = diff;
                idx = i-1;
            }
        }

        if(mini > abs(pre[n-1] / n)) {
            mini = abs(pre[n-1] / n);
            idx = n-1;
        }
        return idx;
    }
};