class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto str : words){
            if(isPalindrome(str)) return str;
        }
        return "";
    }
    
    bool isPalindrome(string s){
        for(int i=0; i<s.size(); i++){
            if(s[i] != s[s.size()-i-1]) return false;
        }
        
        return true;
    }
};