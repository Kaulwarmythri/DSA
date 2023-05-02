class Solution {
public:
    int arraySign(vector<int>& A) {
        int sign = 1;
        
        for(auto &x: A) {
            if(x == 0) 
                return 0;
            if(x < 0) 
                sign = sign * (-1);
        }
        return sign;
    }
};