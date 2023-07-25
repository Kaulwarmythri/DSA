class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size(), i=0, j=arr.size()-1;
        
        while(i < n-1 && arr[i+1] > arr[i]) i++;
        
        while(j > 0 && arr[j-1] > arr[j]) j--;
        
        if(i > 0 && j < n-1 && i==j) return i;
        
        return -1;
    }
};