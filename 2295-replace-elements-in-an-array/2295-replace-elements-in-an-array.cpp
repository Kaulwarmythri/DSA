class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        int n = nums.size(), p = op.size();
        map<int, int> m;
        
        for(int i=0; i<n; i++) m[nums[i]] = i;
    
        for(auto &x : op) {
            nums[m[x[0]]] = x[1];
            m[x[1]] = m[x[0]];
        }
        return nums;
    }
};