class Solution {
public:
    int numSubseq(vector<int>& nums, int X) {
        int n = nums.size(), l = 0, r = n - 1, mod = 1e9 + 7, ans = 0;
        
        sort(nums.begin(), nums.end());
        
        vector<int> pows(n, 1);
        
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        
        while(l <= r) {
            if(nums[l] + nums[r] > X) r--;
            else {
                ans = (ans + pows[r - l++]) % mod;
            }
        }
        return ans;
    }
};