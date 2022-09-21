class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        
        int evensum = accumulate(nums.begin(), nums.end(), 0, [](int s, int a) { 
            return s + (a % 2 == 0 ? a : 0); 
        });
        
        for(auto &q: queries) {
            if(nums[q[1]] % 2 == 0) evensum -= nums[q[1]];
            nums[q[1]] += q[0];
            
            if(nums[q[1]] % 2 == 0) evensum += nums[q[1]];
            ans.push_back(evensum);
        }
        return ans;
    }
};