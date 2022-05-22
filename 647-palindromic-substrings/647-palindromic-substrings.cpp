class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, mid, left, right = 0;
        
        int n = s.size();
        
        for(int i=0; i<n; i++) {
            mid = i;
            left = mid-1;
            right = mid+1;
            
            count++;
            
            //odd length palindrome
            while(left >= 0 && right < n) {
                if(s[left] == s[right]) {
                    left--;
                    right++;
                    count++;
                } else break;
            }
            
            //even length palindrome
            
            if(i < s.size()-1 && s[i] == s[i+1]) {
                count++;
                left = mid-1;
                right = mid+2;
                
                while(left >= 0 && right < n) {
                    if(s[left] == s[right]) {
                        left--;
                        right++;
                        count++;
                    } else break;
                    
                }
            }
        }
        
        return count;
    }
};