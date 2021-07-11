class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        if(x < 0){
            return false;
        }
        long long reverse = 0;
        while(x) {
            reverse = reverse*10 + x%10;
            x /= 10;
        }
        
        if(reverse == y){
            return true;
        }
        
        return false;
    }
};