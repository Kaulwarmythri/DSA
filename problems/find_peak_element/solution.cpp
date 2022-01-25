class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size(), low = 0, high = n-1;
   
       while(low <= high){

            int mid = (low+high) >> 1;

           if((mid == 0 || arr[mid-1] < arr[mid]) && (mid == n-1 || arr[mid] > arr[mid+1]))
               return mid;

           if(mid > 0 && arr[mid-1] > arr[mid]) high = mid-1;
           
           else low = mid+1;
       }
       return 0;
    }
};