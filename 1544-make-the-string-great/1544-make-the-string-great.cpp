class Solution {
public:
    string makeGood(string s) {
        for(int i=0; i+1<s.size(); i++) {
            if(abs(s[i] - s[i+1]) == 32) {
                s = s.substr(0, i) + s.substr(i+2);
                i = max(-1, i-2);     //move it 2 chars behind so that after increment we go to prev element and see if we can find another bad substring
            } 
        }
        return s;
    }
};