//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long countKdivPairs(int A[], int n, int k) {
        long long ans = 0;
        
        vector<int> freq(k, 0);
        
        for(int i=0; i<n; i++) freq[A[i] % k]++;
        
        ans += freq[0] * (freq[0] - 1)/2;
        for(int i=1; i<=k/2 && i != k-i; i++) ans += freq[i] * freq[k-i];
        if(k % 2 == 0) ans += freq[k/2] * (freq[k/2] - 1)/2;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends