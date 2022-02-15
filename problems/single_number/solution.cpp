class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xOR = 0;
        for(auto num : nums) xOR ^= num;
        return xOR;
    }
};