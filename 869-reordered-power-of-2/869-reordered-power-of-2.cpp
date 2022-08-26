class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string N = to_string(n);
        
        sort(N.begin(), N.end());
        
        for(int i=0, pow_of_2 = 1; i<31; i++, pow_of_2 <<= 1) {
            string powOf2 = to_string(pow_of_2);
            sort(powOf2.begin(), powOf2.end());
            
            if(N == powOf2) return true;
        }
        return false;
    }
};