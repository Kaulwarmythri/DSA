class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        unordered_map<int, int> m; m[0] = -1;
        
        int prefix = 0;
        
        for(int i=0; i<nums.size(); i++) {
            prefix += nums[i];
            if(k != 0)
                prefix %= k;
            
            if(m.find(prefix) != m.end()) {
                if(i - m[prefix] > 1)
                    return true;
            } else {
                m[prefix] = i;
            }
        }
        return false;
    }
};