class Solution {
public:
    int lastRemaining(int n) {
        int start = 1, direction = 0, diff = 1;
        
        while(n > 1) {
            
            if(n&1 || direction==0) start += diff;
            
            n /= 2;
            diff *= 2;
            direction = !direction;
        }
        
        return start;
    }
};