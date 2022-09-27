class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size(), count;
        char prev;
        
        #define SET(ch, arr) \
            if(d[i] == ch) {prev = ch; count = 1;} \
            if(d[i] != '.') prev = d[i]; \
            if(prev == ch && d[i] == '.') arr[i] = count++; 
        
        vector<int> left(n, 0), right(n, 0);
        
        for(int i=0; i<n; i++) {
            SET('R', right);
        }
        prev = '.';
        for(int i=n-1; i>=0; i--) {
            SET('L', left);
        }
        
        string res = "";
        for(int i=0; i<n; i++) {
            if(!left[i] && !right[i]) res += d[i];
            else if(!left[i]) res += 'R';
            else if(!right[i]) res += 'L';
            else if(left[i] == right[i]) res += '.';
            else if(left[i] < right[i]) res += 'L';
            else res += 'R';
        }
        return res;
    }
};