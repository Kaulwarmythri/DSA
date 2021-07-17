class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a=0,b=0;
        for(int i=1;i<=nums.size();i++){
            a^=i;
        }
        for(int i=0;i<nums.size();i++){
            b^=nums[i];
        }
        return a^b;
    }
};