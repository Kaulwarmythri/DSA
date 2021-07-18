class Solution {
public:
    string convertToTitle(int columnNumber) {
        char rem;
        string result;
        
        while(columnNumber){
            columnNumber -= 1;
            rem = 'A' + columnNumber%26;
            result = rem + result;
            columnNumber /= 26;
        }
        
        return result;
    }
};