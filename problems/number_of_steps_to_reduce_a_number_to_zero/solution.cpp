class Solution {
public:
    int numberOfSteps(int num) {
        auto steps = 0;
        for(; num>0; (num%2) ? num^=1 : num>>=1) steps++;
        
        return steps;
    }
};