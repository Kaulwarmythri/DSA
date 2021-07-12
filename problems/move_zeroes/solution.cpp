class Solution {
public:
    void swap_args(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }else{
                swap_args(nums[i], nums[i-count]);
            }
        }
    }
};