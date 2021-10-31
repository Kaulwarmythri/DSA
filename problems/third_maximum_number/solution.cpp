class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        return s.size()<3? *max_element(s.begin(), s.end()):*next(s.begin(), s.size()-3);
    }
};