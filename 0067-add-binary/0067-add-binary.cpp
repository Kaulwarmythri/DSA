class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string ans = "";
        
        while(i >= 0 || j >= 0 || carry) {
            if(i >= 0) 
                carry += a[i--] == '1' ? 1 : 0;
            if(j >= 0) 
                carry += b[j--] == '1' ? 1 : 0;
            
            ans = ((carry % 2 == 0) ? '0' : '1') + ans;
            carry /= 2;
        }
        return ans;
    }
};

