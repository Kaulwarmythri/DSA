class Solution {
public:
    string capitalizeTitle(string title) {
        istringstream ss(title);
        string ans;
        for(string word; ss >> word; ){
            for(auto &x : word) x = tolower(x);
            if(word.size() > 2) word[0] = toupper(word[0]);
            ans += word + ' ';
        }
        ans.pop_back();
        return ans;
    }
};


