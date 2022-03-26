class Solution {
public:
    int search(vector<int>& nums, int X) {
        int n = nums.size();
        
        return binarySearch(nums, 0, n-1, X);
    }
    
    int binarySearch(vector<int> &nums, int l, int r, int X){
        
        while(l <= r) {
            int mid = (l + r)/2;
            
            if(X == nums[mid]) return mid;
            
            else if(X > nums[mid]) return binarySearch(nums, mid+1, r, X);
            
            else return binarySearch(nums, l, mid-1, X);
        }
        
        return -1;
    }
};