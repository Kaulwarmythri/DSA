class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, N = nums.size(), sum = 0;
        unordered_set<int> s;
        for (int i = 0, j = 0; j < N; ++j) {
            while (s.count(nums[j])) {
                s.erase(nums[i]);
                sum -= nums[i++];
            }
            s.insert(nums[j]);
            sum += nums[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};