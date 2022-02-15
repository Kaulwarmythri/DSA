class Solution {
public:
    int n;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        set<vector<int>> s;
        solve(nums, 0, curr, s, INT_MIN);
        return vector<vector<int>>(s.begin(), s.end());
    }
    
    void solve(vector<int>&nums, int i, vector<int>&curr, set<vector<int>>&s, int prev){
        if(i==nums.size()) return;
        
        for(int j=i; j<n; j++){
            if(nums[j] >= prev){
                curr.push_back(nums[j]);
                if(curr.size() >= 2) s.insert(curr);
                solve(nums, j+1, curr, s, nums[j]);
                curr.pop_back();
            }
        }
        
    }
};
