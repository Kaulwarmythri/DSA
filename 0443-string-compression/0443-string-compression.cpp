class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0;
        
        for(int j=1, count=1; j<=n; j++, count++) {
            if(j == n || chars[j] != chars[j-1]) {
                chars[i++] = chars[j-1];
                
                if(count > 1) {
                    for(auto &digit: to_string(count)) chars[i++] = digit;
                }
                count = 0;
            }
        }
        return i;
    }
};