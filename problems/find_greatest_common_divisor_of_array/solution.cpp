class Solution {
public:
    int findGCD(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int l=nums[0], r=nums[nums.size()-1];
        return std::gcd(l, r);
    }
};