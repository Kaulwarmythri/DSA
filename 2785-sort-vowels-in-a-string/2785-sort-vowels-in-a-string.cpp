class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowels;
        
        for(auto &c: s) 
            if(string("AEIOUaeiou").find(c) != string::npos)
                vowels.push_back(c);
        
        sort(vowels.begin(), vowels.end(), greater<char>());
        
        string ans = "";
        
        for(auto &c: s) {
            if(string("AEIOUaeiou").find(c) == string::npos)
                ans += c;
            else {
                ans += vowels.back(); vowels.pop_back();
            }
        }
        return ans;
    }
};