//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    long long nextGap(long long gap) {
        if(gap <= 1) return 0;
        
        return gap / 2 + gap % 2;
    }
    
public:
    void merge(long long arr1[], long long arr2[], int m, int n) { 
        long long i, j, gap = nextGap(m + n);
        
        for(gap; gap>0; gap = nextGap(gap)) {
            for(i = 0; i + gap < m; i++) {
                if(arr1[i] > arr1[i + gap]) swap(arr1[i], arr1[i + gap]);
            }
            
            for(j = gap > m ? gap - m : 0; i < m && j < n; i++, j++) {
                if(arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);
            }
            
            if(j < n) {
                for(j = 0; j + gap<n; j++) {
                    if(arr2[j] > arr2[j + gap]) swap(arr2[j], arr2[j + gap]);
                }
            }
        }
    } 
    
    
    
};


//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends