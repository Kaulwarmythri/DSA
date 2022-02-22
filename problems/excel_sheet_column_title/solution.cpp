class Solution {
public:
    string convertToTitle(int columnNumber) {
        char rem;
        string ans;
        
        while(columnNumber){
            columnNumber -= 1;
            rem = 'A' + columnNumber%26;
            ans = rem + ans;
            columnNumber /= 26;
        }
        
        return ans;
    }
};