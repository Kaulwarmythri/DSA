class Solution {
    map<int, string, greater<int>> m = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };
public:
    string intToRoman(int num) {
        string ans = "";
        
        map<int, string, greater<int>>::iterator p = m.begin();
        while(num) {
            while(p->first > num) p++;
            num -= p->first;
            ans += p->second;
        }
        
        return ans;
    }
};

