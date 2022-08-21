class Solution {
    int n;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size(); 
        if(k == 1) return true;
        if(n < k) return false;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return false;
        
        int subsetSum = sum / k;
        vector<int> subsets(k, 0);
        vector<bool> used(n, false);
        
        subsets[0] = nums[n-1];
        used[n-1] = true;
        
        return solve(nums, subsets, used, subsetSum, k, 0, n-1);
    }
    
    bool solve(vector<int> &nums, vector<int> &subsets, vector<bool> &used, int subsetSum,  int k, int currIdx, int limIdx) {
        if(subsets[currIdx] == subsetSum) {
            if(currIdx == k-2) return true;
            return solve(nums, subsets, used, subsetSum, k, currIdx+1, n-1);
        }
        
        for(int i=limIdx; i>=0; i--) {
            if(used[i]) continue;
            int temp = subsets[currIdx] + nums[i];
            
            if(temp <= subsetSum) {
                subsets[currIdx] += nums[i];
                used[i] = true;
                
                bool next = solve(nums, subsets, used, subsetSum, k, currIdx, i-1);
                
                subsets[currIdx] -= nums[i];
                used[i] = false;
                
                if(next) return true;
            }    
        }
        return false;
    }
};