class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if(n < 3 || nums[0] > 0) return {};
        
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++) m[nums[i]]= i;
        
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            for(int j=i+1; j<n; j++) {
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                
                if(m[-(nums[i] + nums[j])] > j) {
                    ans.push_back({nums[i], nums[j], -(nums[i] + nums[j])});
                }
            }
        }
        return ans;
    }
};
