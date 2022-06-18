class TrieNode {
public: 
    TrieNode* children[27] = {nullptr};
    int index = 0;
};


class Trie {
public: 
    TrieNode* root; 
    Trie() { 
        root = new TrieNode(); 
    }

    void insert(string word, int i) {
        TrieNode* node = root; 
        for (auto& c : word) {
            if (!node->children[c - 'a']) 
                node->children[c - 'a'] = new TrieNode(); 
            node = node->children[c - 'a'];
            node->index = i; 
        }
    }

    int prefix(string word) {
        TrieNode* node = root; 
        for (auto& letter : word) {
            node = node->children[letter - 'a']; 
            if (!node) return -1; 
        }
        return node->index; 
    }
};


class WordFilter {
    Trie* trie; 
public:
    WordFilter(vector<string>& words) {
        trie = new Trie(); 
        for (int i = 0; i < size(words); ++i) {
            for (int j = 0; j < words[i].size(); j++) {
                string key = words[i].substr(j) + "{" + words[i]; 
                trie->insert(key, i); 
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string key = suffix + "{" + prefix; 
        return trie->prefix(key); 
    }
};



/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */