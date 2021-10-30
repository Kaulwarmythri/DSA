class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(65, 0);
        int len=0;
        for(char c : s){
            v[c-65]++;
        }
        for(int i : v){
            if(i%2==0) len+=i;
            else len += (i-1);
        }
        return len==s.size()?len:len+1;
        
    }
};