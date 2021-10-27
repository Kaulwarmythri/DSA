class Solution {
public:
    bool isPrime(int n){
        if(n==0 || n==1) return false;
        for(int i=2;i<n/2;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    bool isThree(int n) {
        return n!=2 && (int)sqrt(n)*sqrt(n)==n && isPrime(sqrt(n));
    }
};