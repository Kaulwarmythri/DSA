class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX, n = nums.size(), ans = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r], difference = abs(target - sum);
                if(sum == target) return sum;
                if(difference < diff) {
                    diff = difference;
                    ans = sum;
                } 
                if(sum > target) r--;
                else l++;
            }
        } 
        return ans;
    }
};