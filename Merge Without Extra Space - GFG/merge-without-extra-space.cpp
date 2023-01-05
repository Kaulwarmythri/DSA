//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
public:
    void merge(long long a1[], long long a2[], int m, int n) { 
        long long i = 0, j = 0, gap = nextGap(m + n);
        
        for(gap; gap > 0; gap = nextGap(gap)) {
            for(i = 0; i + gap < m; i++) {
                if(a1[i] > a1[i + gap]) swap(a1[i], a1[i + gap]);
            }
            
            for(j = gap > m ? gap - m : 0; i < m && j < n; i++, j++) {
                if(a1[i] > a2[j]) swap(a1[i], a2[j]);
            }
            
            if(j < n) {
                for(j = 0; j + gap < n; j++) {
                    if(a2[j] > a2[j + gap]) swap(a2[j], a2[j + gap]);
                }
            }
        }
    } 
    
    long long nextGap(int a) {
        if(a <= 1) return 0;
        return a / 2 + a % 2;
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