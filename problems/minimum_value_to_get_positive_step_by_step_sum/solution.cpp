class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min=0, sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            min = std::min(min, sum);
        }
        return 1-min;
    }
};