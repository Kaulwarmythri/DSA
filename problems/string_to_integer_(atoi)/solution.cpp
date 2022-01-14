class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;
        int i=0, sign = 1;
        
        while(s[i]==' ' && i<s.size()) i++;
        if(s[i]=='+' || s[i]=='-'){ sign = (s[i]=='+') ? 1 : -1; i++; }
        while(i < s.size() && isdigit(s[i])){
            ans = ans*10 + (s[i]-'0');
            if(ans > INT_MAX || ans < INT_MIN) return (sign==1) ? INT_MAX : INT_MIN;
            i++;
        }
        return ans*sign;
    }
};

/*
int n = s.size();
    int sign=1;
    int i=0;
    
    while(s[i]==' ' and i<n) //ignoring the white spaces
    {
        i++;
    }
    if(s[i]=='-' ) // to include negative sign
    {
        sign=-1;
        i++;
    }
    else if(s[i]=='+') // for +1 input we take + first as sign and increase the i value
    {
        sign=1;
        i++;
    }
    
   long long int ans=0;
    while(i < n && s[i] >= '0' && s[i] <= '9')
    {
            ans = ans*10 + s[i]-'0';
           
        if(ans > INT_MAX || ans < INT_MIN)
         return sign == 1 ? INT_MAX : INT_MIN;
        
        i++;
    }
    return ans*sign;
*/