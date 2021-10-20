class Solution {
public:
    string reverseVowels(string s) {
         int i = 0, j = s.length()-1;
        
        while(i <  j) {
            if(isVowel(s[i]) and isVowel(s[j])) {
                swap(&s[i], &s[j]);
                i++, j--;
            }
            
            else if(isVowel(s[i])) j--;
            else i++;
        }
        return s;
        
        
    }
    
    void swap(char *a, char *b){
        char temp = *a;
        *a = *b;
        *b = temp;
    }
    bool isVowel(char i){
        return i=='a' || i=='e' || i=='i' || i=='o' || i=='u' || 
            i=='A' || i=='E' || i=='I' || i=='O' || i=='U';
    }
};