class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int n = s.size(), i = 0, j = 0, len = 0;
        
        vector<int> arr(256, 0);
        
        while(j < n) {
            if(arr[s[j]] < 1) {
                len = max(len, j-i+1);
                arr[s[j]]++;
                j++;
            } else {
                arr[s[i]]--;
                i++;
            }
        }
        return len;
    }
};