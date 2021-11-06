class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0, b=0;
        long long xOR=nums[0], setBit;
        vector<int> v;
        for(int i=1;i<nums.size();i++) xOR^=nums[i];
        setBit = xOR&~(xOR-1);
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]&setBit) a=a^nums[i];
            else b=b^nums[i];
        }
        return v={a, b};
        
    }
};