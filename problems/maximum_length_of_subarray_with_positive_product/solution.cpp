class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos=0, neg=0, ans=0;
        
        for(auto &x : nums){
            if(x==0) pos=neg=0;
            else if(x<0){
                swap(pos, neg);
                ++neg;
                pos = pos ? pos+1 : 0;
            }else{
                ++pos;
                neg = neg ? neg+1 : 0;
            }
            ans=max(ans, pos);    
        }
        return ans;
    }
};