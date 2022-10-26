class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2)
            return false;
       unordered_map<int, int> mp;
        mp[0]=-1;
        
        int runningSum=0;
        
        for(int i=0; i<nums.size();i++) {
            runningSum+=nums[i];
            
            if(k!=0) 
                runningSum = runningSum%k;
            
            if(mp.find(runningSum)!=mp.end()) { 
                if(i-mp[runningSum]>1)
                    return true;
            }
            else mp[runningSum]=i;       
        }
        
        return false;
    }
};




//m[0] = -1 will help if for the last element the sum becomes a multiple of 6 ==> Eg. [1, 2, 3]
//It can also prevent returning true if only 1 element (Eg. element at 0th index) is a multiple of k (Since 0 - (-1) != > 1).