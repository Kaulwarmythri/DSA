class Solution {
    vector<int> bits;
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX, i = 0, j = 0;
        bits.resize(32, 0);
        
        while(j < n) {
            incrementBitCount(nums[j], true);
            
            while(i <= j && convertToNum(bits) >= k) {
                ans = min(ans, j - i + 1);
                
                incrementBitCount(nums[i++], false);
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
    
    void incrementBitCount(int num, bool increment) {
        for(int pos=0; pos<32; pos++) {
            if((num >> pos) & 1)
                bits[pos] = increment ? bits[pos] + 1 : bits[pos] - 1;
        }
    }
    
    int convertToNum(vector<int> &bits) {
        int num = 0;
        for(int pos=0; pos<32; pos++) {
            if(bits[pos] != 0)
                num |= (1 << pos); 
        }
        return num;
    }
};