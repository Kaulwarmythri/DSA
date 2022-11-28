//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    long long int inversionCount(long long arr[], long long n) {
        long long temp[n];
        return mergeSort(arr, temp, 0, n-1);
    }
    
    long long mergeSort(long long arr[], long long temp[], long long l, long long r) {
        long long count = 0, mid = 0;
        if(l < r) {
            mid = l + (r - l)/2;
            count += mergeSort(arr, temp, l, mid);
            count += mergeSort(arr, temp, mid+1, r);
            count += merge(arr, temp, l, mid, r);
        }
        return count;
    }
    
    long long merge(long long arr[], long long temp[], long long l, long long mid, long long r) {
        long long count = 0, i = l, j = mid+1, k = l;
        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else {
                count += mid - i + 1;
                temp[k++] = arr[j++];
            }
        }
        while(i <= mid) temp[k++] = arr[i++];
        while(j <= r) temp[k++] = arr[j++];
        
        for(i=l; i<=r; i++) arr[i] = temp[i];
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends