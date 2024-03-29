class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) 
            return "0";
        
        string ans;
        if (numerator > 0 ^ denominator > 0) 
            ans += '-';
        
        long n = labs(numerator), d = labs(denominator), r = n % d;
        ans += to_string(n / d);
        if (!r) 
            return ans;
        ans += '.';
        unordered_map<long, int> m;
        while (r) {
            if (m.find(r) != m.end()) {
                ans.insert(m[r], "(");
                ans += ')';
                break;
            }
            m[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        return ans;
    }
};