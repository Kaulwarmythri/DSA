class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), l = -1, r = -1, max = INT_MIN;
        
        for(int i=0; i<n; i++) {
            if(max > nums[i]) {
                
                if(l == -1) l = i-1;
                while(l-1 >= 0 && nums[l-1] > nums[i]) l--;
                
                r = i+1;
                
            } else max = nums[i];
        }
        return r - l;    
    }
};