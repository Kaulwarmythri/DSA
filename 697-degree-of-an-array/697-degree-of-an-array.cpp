class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), ans = 0, degree = 0;
        unordered_map<int, int> counts, first;
        
        for(int i=0; i<n; i++) {
            if(first.count(nums[i]) == 0) first[nums[i]] = i;
            if(++counts[nums[i]] > degree) {
                degree = counts[nums[i]];
                ans = i - first[nums[i]] + 1;
            } else if(counts[nums[i]] == degree) {
                ans = min(ans, i - first[nums[i]] + 1);
            }
        }
        return ans;
        
    }
};