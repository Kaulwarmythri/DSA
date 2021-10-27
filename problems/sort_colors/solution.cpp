class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3];
        int i=0,k=0;
        arr[0] = count(nums.begin(), nums.end(), 0);
        arr[1] = count(nums.begin(), nums.end(), 1);
        arr[2] = count(nums.begin(), nums.end(), 2);
        for(i;i<3;i++){
            while(arr[i]--){
                nums[k++]=i;
            }
        }
    }
};