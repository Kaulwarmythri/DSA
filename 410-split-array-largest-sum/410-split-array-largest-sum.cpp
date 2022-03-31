class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        int low = *max_element(nums.begin(), nums.end());
        
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low < high) {
            int mid = low + (high-low)/2;
            
            if(isPossible(nums, mid, m)) high = mid;
            
            else low = mid + 1;
        }
        return low;
    }
    
    bool isPossible(vector<int> nums, int sum, int m) {
        int curr_sum = 0, splits = 0;
        
        for(auto num : nums) {
            curr_sum += num;
            
            if(curr_sum > sum) {
                curr_sum = num;
                splits++;
            }
            
            if(splits > m-1) return false;
            
        }
        return true;
    }
};

