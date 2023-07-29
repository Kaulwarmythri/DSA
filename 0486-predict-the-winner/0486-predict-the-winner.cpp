class Solution {
    int n;
public:
    bool PredictTheWinner(vector<int>& nums) {
        n = nums.size();
        long long one, two=0;
        
        two = accumulate(nums.begin(), nums.end(), 0);
        one = solve(nums, 0, n-1, 0);
        
        two -= one;
        return (one >= two);
    }
    
    int solve(vector<int> &nums, int i, int j, int turn) {
        if(i > j) return 0;
        
        if(!turn) 
            return max(nums[i] + solve(nums, i+1, j, 1), nums[j] + solve(nums, i, j-1, 1));
        else 
            return min(solve(nums, i+1, j, 0), solve(nums, i, j-1, 0));
        
    }
};