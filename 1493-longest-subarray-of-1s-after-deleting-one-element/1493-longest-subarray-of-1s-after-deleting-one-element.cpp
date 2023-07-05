class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) 
            return 0;
        
        int count = 0, l=0, r=0, max_len = 0;
        while(r < n){
            if(!nums[r]) 
                count++;
            while(count > 1){
                if(!nums[l]) 
                    count--;
                l++;
            }
            max_len = max(max_len, r - l);
            r++;
        }
        return max_len;
    }
};