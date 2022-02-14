class Solution {
public:
    int minOperations(int n) {
        int target = (1 + 2*(n-1) + 1)/2, min_op=0;
        for(int i=0; i<n/2; i++) min_op += target - (2*(i) + 1);
        
        return min_op;
    }
};