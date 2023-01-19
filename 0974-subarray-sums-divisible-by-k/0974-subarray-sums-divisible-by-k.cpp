class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> seen(k);
        
        int ans = 0, pref_sum = 0;
        seen[pref_sum]++;
        
        for(auto &x: nums) {
            pref_sum = (pref_sum + x) % k;
            if(pref_sum < 0) pref_sum += k;
            ans += seen[pref_sum];
            seen[pref_sum]++;
        }
        return ans;
    }
};
