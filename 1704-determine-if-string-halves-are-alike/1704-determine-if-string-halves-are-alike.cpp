class Solution {
public:
    bool halvesAreAlike(string s) {
        int vowelDiff = 0, mid = s.size()/2;
        
        for(int i=0; i<mid; i++) vowelDiff += isVowel(s[i]) - isVowel(s[mid+i]);
        
        return !vowelDiff;
    }
    
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};