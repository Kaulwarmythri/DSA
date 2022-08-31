class Solution {
    int n;
public:
    void wiggleSort(vector<int>& nums) {
        n = nums.size(); int mid = n/2;
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        
        threeWayPartition(nums, nums[mid]);
        vector<int> ans(n);
        
        int l = n%2 ? mid : mid-1, r = n-1;
        for(int i=0; i<n; i+=2) 
            ans[i] = nums[l--];
        for(int i=1; i<n; i+=2) 
            ans[i] = nums[r--];
        
        nums = ans;
    }
    
    void threeWayPartition(vector<int> &nums, int val) {
        int i=0, j=0, k=n-1;
        
        while(j <= k) {
            if(nums[j] < val) 
                swap(nums[i++], nums[j++]);
            else if(nums[j] > val) 
                swap(nums[j], nums[k--]);
            else
                j++;
        }
    }
    
    
};