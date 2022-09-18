class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        istringstream in(s);
        string word;
        
        while(in >> word) {
            ans++;
        }
        
        return ans;
    }
};