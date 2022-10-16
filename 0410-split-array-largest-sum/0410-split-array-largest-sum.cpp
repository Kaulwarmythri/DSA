class Solution {
    int n;
public:
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        int l = *max_element(nums.begin(), nums.end()), 
        r = accumulate(nums.begin(), nums.end(), 0),
        ans = 0, mid = 0;
        
        while(l <= r) {
            mid = l + (r-l) / 2;
            if(check(nums, mid, k)) {
                r = mid-1;
                ans = mid;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
    
    bool check(vector<int> &nums, int mid, int k) {
        int sum = 0, count = 0;
        for(int i=0; i<n; i++) {
            if(sum + nums[i] > mid) {
                sum = 0;
                count++;
            }
            sum += nums[i];
        }
        return count < k;
    }
};