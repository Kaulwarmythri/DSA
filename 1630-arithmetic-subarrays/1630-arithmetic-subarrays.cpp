class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        
        vector<bool> ans;
        
        for(int i=0; i<m; i++) {
            vector<int> subarray(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans.push_back(check(subarray));
        }
        
        return ans;
    }
    
    bool check(vector<int> &A) {
        sort(A.begin(), A.end());
        int diff = A[1] - A[0];
        
        for(int i=2; i<A.size(); i++) 
            if(A[i] - A[i-1] != diff)
                return false;
    
        return true;
    }
};