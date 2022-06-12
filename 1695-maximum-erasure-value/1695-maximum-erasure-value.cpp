class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, ans = 0, sum = 0;
        unordered_set<int> s;
        while(r < n) {
            if(s.count(nums[r]) < 1) {
                s.insert(nums[r]);
                sum += nums[r++];
                ans = max(ans, sum);
            } else {
                s.erase(nums[l]);
                sum -= nums[l++];
            }
        }
        return ans;
    }
};