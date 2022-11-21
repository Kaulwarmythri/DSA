//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

string reverseWord(string s){
    int l = 0, r = s.size()-1;
    
    while(l < r) {
        swap(&s[l++], &s[r--]);
    }
    return s;
}

