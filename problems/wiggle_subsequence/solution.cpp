class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int lastSign=0, ans=1;
        for(int i=1;i<nums.size();i++){
            int sign = signum(nums[i]-nums[i-1]);
            if(sign != lastSign && sign != 0){
                lastSign = sign;
                ans++;
            }
        }
        return ans;
    }
    
    int signum(int n){
        if(n!=0){
            return n>0?1:-1;
        }else return 0;
    }
};