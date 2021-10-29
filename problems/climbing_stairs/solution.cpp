class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> A(n);
        A[0]=1; //1 step
        A[1]=2; //2 steps
        for(int i=2;i<n;i++){
            A[i]=A[i-1]+A[i-2];
        }
        return A[n-1];
        
    }
};