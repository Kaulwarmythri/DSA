class Solution {
public:
    int maximum69Number (int num) {
        int temp = num, left_most_6 = -1;
        
        for(int i=1; temp > 0; i *= 10, temp /= 10) 
            if(temp % 10 == 6) left_most_6 = i;
            
        return left_most_6 == -1 ? num : num + 3 * left_most_6;
    }
};