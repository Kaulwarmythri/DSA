class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xOR=0, a=0, b=0, rightSetBit;
        vector<int> v;
        for(int i=0;i<nums.size();i++) xOR^=nums[i];
        for(int i=1;i<=nums.size();i++) xOR ^= i;
        //left with the xOR of repating and missing numbers
        rightSetBit = xOR&~(xOR-1);
        for(int i=0;i<nums.size();i++){
            if(rightSetBit&nums[i]) a ^= nums[i];
            else b ^= nums[i]; 
            
        }
        for(int i=1;i<=nums.size();i++){
            if(rightSetBit&i) a ^= i;
            else b ^= i; 
            
        }
         for (auto n : nums)
            if (n == a)
                return {a, b};
        return {b, a};
        
        
        
        
        
        
        
    }
};