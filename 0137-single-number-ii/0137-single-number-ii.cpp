class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(int i=0; i<=31; i++) {
            int bit = (1 << i), count = 0;
            
            for(auto &x: nums) if(x & bit) count++;
            
            if(count % 3) ans |= bit;
        }
        return ans;
    }
};