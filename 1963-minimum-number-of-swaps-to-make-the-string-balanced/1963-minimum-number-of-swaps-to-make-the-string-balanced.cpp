class Solution {
public:
    int minSwaps(string s) {
        int n = s.size(), size = 0;
        
        for(auto &c: s) {
            if(c == '[') size++;
            else {
                if(size > 0) size--;
            }
        }
        return (size + 1) / 2;
    }
};