class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), ans = n, rem = 0;
        
        for(int i=0; i<n; i++) 
            rem = (rem + nums[i]) % p;
        
        if(rem % p == 0)
            return 0;
        int cur = 0;
        unordered_map<int, int> m; m[0] = -1;
        
        for(int i=0; i<n; i++) {
            cur = (cur + nums[i]) % p;
            int X = (cur - rem + p) % p;
            
            if(m.find(X) != m.end()) {
                ans = min(ans, i - m[X]);
            }
            m[cur] = i;
        }
        return ans < n ? ans : -1;
    }
};