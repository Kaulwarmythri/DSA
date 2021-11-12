class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int num1=0, n=nums.size();
        for(int i=0;i<n;i++) if(nums[i]==1) num1=1;
        if(num1==0) return 1;
        
         for(int i =0 ; i<n ;i++) {
            if(nums[i] > n || nums[i] <= 0) nums[i] = 1;
        }
        for(int i =0;i<n ;i++) nums[(nums[i]-1) %n] += n; 

        for(int i =0 ; i<n ;i++) {
            if(nums[i] <= n) {
              return i+1;
            }
        }
        return n+1;
    }
};