class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), count=0, prefixSum=0;
        map<int, int> seen;
        
        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            
            if(prefixSum == k) count++;
            if(seen.count(prefixSum - k)) count += seen[prefixSum - k];
            seen[prefixSum]++;
        }
        return count;
    }
};