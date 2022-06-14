class Solution {
public:
    char findKthBit(int n, int k) {
        return solve(n, k) + '0';
    }
    
    int solve(int n, int k) {
        if(n == 1 || k == 1) return 0;
        if(k == pow(2, n)/2 || k == pow(2, n) - 1) return 1;
        if(k < pow(2, n)/2) return solve(n-1, k);
        if(k > pow(2, n)/2) return !solve(n-1, pow(2, n) - k);
        
        return 0;
    }
    
    
};