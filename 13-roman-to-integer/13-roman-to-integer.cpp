class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m.insert(make_pair('I', 1));
        m.insert(make_pair('V', 5));
        m.insert(make_pair('X', 10));
        m.insert(make_pair('L', 50));
        m.insert(make_pair('C', 100));
        m.insert(make_pair('D', 500));
        m.insert(make_pair('M', 1000));
        
        int ans = m[s.back()];
        for(int i=s.size()-2; i>=0; i--) {
            if(m[s[i]] >= m[s[i+1]]) ans += m[s[i]];
            else ans -= m[s[i]];
        }
        return ans;
        
    }
};