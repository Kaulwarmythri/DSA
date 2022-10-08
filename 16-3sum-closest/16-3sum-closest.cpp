class Solution {
public:
    int threeSumClosest(vector<int>& nums, int X) {
        int ans = INT_MAX, diff = INT_MAX, n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r], difference = abs(X - sum);
                if(sum == X) return sum;
                if(difference < diff) {
                    diff = difference;
                    ans = sum;
                }
                if(sum > X) r--;
                else l++;
            }
        }
        return ans;
    }
};