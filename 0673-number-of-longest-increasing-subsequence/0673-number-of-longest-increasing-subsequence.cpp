class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), max_len = 1, ans = 0;
        
        vector<int> lis(n, 1), cnt(n, 1);
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    if(lis[i] < lis[j] + 1) {
                        lis[i] = lis[j] + 1;
                        cnt[i] = cnt[j];
                    } else if(lis[i] == lis[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            max_len = max(max_len, lis[i]);
        }
        
        for(int i=0; i<n; i++) {
            if(lis[i] == max_len) ans += cnt[i];
        }
        return ans;
    }
};