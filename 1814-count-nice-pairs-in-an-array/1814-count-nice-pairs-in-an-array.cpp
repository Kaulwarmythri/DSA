class Solution {
    int mod = 1e9 + 7;
    
    int reverse(int num) {
        int rev = 0;
        
        while(num) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++) 
            nums[i] -= reverse(nums[i]);
        
        sort(nums.begin(), nums.end());

        long res = 0;
        for (int i = 0; i < n - 1; ++i) {
            long count = 1;
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                count++;
                i++;
            }
            res = (res % mod + (count * (count - 1)) / 2) % mod;
        }

        return static_cast<int>(res % mod);
    }
};


//nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]);
// ==> nums[i] - rev(nums[i]) == nums[j] - rev(nums[j]);