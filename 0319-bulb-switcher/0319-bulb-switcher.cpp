class Solution {
public:
    int bulbSwitch(int n) {
        int count = 0;
        
        for(int i=1; i * i <= n; i++) 
            count++;
    
        return count;
    }
};


//i'th bulb is toggled at every factor of 'i'.
//If the no. of factors (including 1) is even...it's off at last, otherwise it's on.
//So to find the number of bulbs that is on...we need to find the numbers with odd no. of factors from 1 to n.
//Only perfect squares have off number of factors.