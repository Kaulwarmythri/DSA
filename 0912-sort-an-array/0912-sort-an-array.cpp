class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums, 0, nums.size() - 1);
        
        return nums;
    }
    
    void MergeSort(vector<int> &nums, int l, int r) {
        if(l < r) {
            int mid = l + (r - l) / 2;
            MergeSort(nums, l, mid);
            MergeSort(nums, mid + 1, r);
            Merge(nums, l, mid, r);
        }
    }
    
    void Merge(vector<int> &nums, int l, int mid, int r) {
        int i = 0, j = 0, k = mid + 1, n1 = mid - l + 1, n2 = r - mid;
        vector<int> L(n1, 0), R(n2, 0);
        
        
        for(int i=0; i<n1; i++) 
            L[i] = nums[l + i];
        
        for(int j=0; j<n2; j++)
            R[j] = nums[mid + 1 + j];
        
        i=0; j=0; k=l;
        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) nums[k++] = L[i++];
            else nums[k++] = R[j++];
        } 
        
        while(i < n1) nums[k++] = L[i++];
        
        while(j < n2) nums[k++] = R[j++];
    }
};