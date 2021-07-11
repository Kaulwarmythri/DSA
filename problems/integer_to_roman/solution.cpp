class Solution {
public:
    string intToRoman(int num) {
        
         map<int, string, greater<int>> m;
            m.insert(make_pair(1000, "M"));
            m.insert(make_pair(900, "CM"));
            m.insert(make_pair(500, "D"));
            m.insert(make_pair(400, "CD"));
            m.insert(make_pair(100, "C"));
            m.insert(make_pair(90, "XC"));
            m.insert(make_pair(50, "L"));
            m.insert(make_pair(40, "XL"));
            m.insert(make_pair(10, "X"));
            m.insert(make_pair(9, "IX"));
            m.insert(make_pair(5, "V"));
            m.insert(make_pair(4, "IV"));
            m.insert(make_pair(1, "I"));
        
        map<int, string>::iterator p = m.begin();
        string roman;
        while(num > 0 && p != m.end()){
            if(num >= p->first){
                num -= p->first;
                roman += p->second;
            }else{
                p++;
            }
        }
        
        return roman;
    }
};