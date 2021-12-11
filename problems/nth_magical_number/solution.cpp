class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = a*b/gcd(a, b);
        long long l = 0, r = (long long) n*min(a, b);
        
        while(l < r){
            long mid = l+(r-l)/2;
            if(mid/a + mid/b - mid/lcm < n) l = mid+1;  
            else r = mid;
        }
        return l%(1'000'000'007);
    }
};