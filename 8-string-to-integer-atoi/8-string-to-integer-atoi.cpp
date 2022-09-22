class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;
        int i=0, sign = 1;
        
        while(s[i]==' ' && i<s.size()) i
            ++;
        if(s[i]=='+' || s[i]=='-')
            sign = (s[i]=='+') ? 1 : -1, i++; 
        
        while(i < s.size() && isdigit(s[i])) {
            ans = ans*10 + (s[i]-'0');
            if(ans > INT_MAX) return (sign==1) ? INT_MAX : INT_MIN;
            i++;
        }
        return ans*sign;
    }
};
