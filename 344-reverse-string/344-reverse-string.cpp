class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0, j=s.size()-1;
        solve(s, i, j);
    }
    
    void solve(vector<char> &s, int i, int j) {
        if(i > j) return;
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        
        solve(s, i+1, j-1);
    }
};