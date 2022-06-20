class TrieNode {
public:   
    TrieNode *children[26] = {};
    bool isEnd = false;
};

class Solution {
    TrieNode *root = new TrieNode();
public:
    int insert(string s) {
        TrieNode *curr = root;
        int res = 0;

        for(int i=s.size()-1; i>=0; i--) {
            
            if(!curr->children[s[i] - 'a']) {
                curr->children[s[i]-'a'] = new TrieNode();
                
                if(!i) res += s.size() + 1;
            }
            
            if(curr->isEnd) {
                res -= s.size() - i;
                curr->isEnd = false;
            }
            curr = curr->children[s[i] - 'a'];
        }
        if(curr->isEnd) return 0;
        curr->isEnd = res > 0 ? 1 : 0;
        
        return res;
    }

    int minimumLengthEncoding(vector<string>& words) {
        return accumulate(words.begin(), words.end(), 0, [this](int a, string b) {
            return a + insert(b);
        });
    }
};