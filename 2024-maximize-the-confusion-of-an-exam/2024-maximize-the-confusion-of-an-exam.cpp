class Solution {
public:
    int maxConsecutiveAnswers(string S, int k) {
        int n = S.size(), l = 0, r = 0, ans = 0, count = 0;
        
        //change to 'T'
        while(r < n) {
            if(S[r] == 'F') count++;
            
            while(count > k) {
                if(S[l] == 'F') 
                    count--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        
        l = 0, r = 0, count = 0;
        while(r < n) {
            if(S[r] == 'T') count++;
            
            while(count > k) {
                if(S[l] == 'T')
                    count--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        
        return ans;
    }
};