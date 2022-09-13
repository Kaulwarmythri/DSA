class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size(), count = 0;
        
        for(auto &d: data) {
            if(!count) {
                if((d >> 5) == 0b110)  //2-byte 
                    count = 1;     //1 more byte left
                
                else if((d >> 4) == 0b1110)  //3-byte
                    count = 2;    //2 more bytes left
                else if((d >> 3) == 0b11110)  //4-byte 
                    count = 3;   //3 more bytes left
                else if((d >> 7))
                    return false;
            } else {
                if((d >> 6) != 0b10)
                    return false;
                count--;
            }
        }
        return count == 0;
    }
};