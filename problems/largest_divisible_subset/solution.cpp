class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());  //sorting it so that we know that for nums[i], index such that nums[i]%nums[j] is always on it's left.
        int n = nums.size(), max{}, index{};
        vector<int> lis(n, 1);
        vector<int> prev_idx(n, -1);
        
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(lis[i]<lis[j]+1 && nums[i]%nums[j]==0){
                     lis[i]=lis[j]+1; 
                     prev_idx[i]=j;
                }
            }
            
            if(max < lis[i]){
                max = lis[i];
                index=i;
            }
        }
        
        vector<int> lds;
        while(index != -1){
            lds.push_back(nums[index]);
            index = prev_idx[index];
        }
        
        return lds;
    }
};


