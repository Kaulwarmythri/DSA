class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        
        for(; num > 0; (num&1) ? num ^= 1 : num >>= 1) steps++;
        
        return steps;
    }
};