class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mid = nums[(n-1)/2];
        
        return accumulate(nums.begin(), nums.end(), 0, [mid](long a, int b){
            return a + abs(b - mid);
        });
    }
};