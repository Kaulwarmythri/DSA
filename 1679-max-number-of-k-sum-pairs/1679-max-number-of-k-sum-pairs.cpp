class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        
        for(auto n : nums) m[n]++;
        
        for(auto &[key, val] : m) {
            if(2*key == k) ans += val/2, val -= val/2*2;
            
            else if(val > 0 && m.count(k - key) && m[k - key] > 0) {
                int cnt = min(val, m[k - key]);
                ans += cnt;
                val -= cnt;
                m[k- key] -= cnt;
            }
        }
        return ans;
    }
};