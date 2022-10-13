//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int kthSmallest(int arr[], int l, int r, int K) {
        if (K > 0 && K <= r - l + 1) {
            int pos = partition(arr, l, r);
 
            if (pos - l == K - 1) 
            return arr[pos];
            if (pos - l > K - 1)
                return kthSmallest(arr, l, pos - 1, K);
                
            return kthSmallest(arr, pos + 1, r,
                               K - pos + l - 1);
        }
    }
    
    int partition(int arr[], int l, int r) {
        int i = l-1, pivot = arr[r];
        
        for(int j=l; j<r; j++) {
            if(arr[j] < pivot) {
                swap(arr[++i], arr[j]);
            }
        }
        swap(arr[++i], arr[r]);
        return i;
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends