class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,len=0;
        map<char, int> m;
        while(j < s.size()){
            if(m[s[j]] < 1){
                len = max(len, j-i+1);
                m[s[j]]++;
                j++;
            }else{
                m[s[i]]--;
                i++;
                  
            }
        }
        return len;
        
    }
};