class TrieNode {
public:
    TrieNode *children[26];
    bool isEnd;
    
    TrieNode() {
        isEnd = false;
        for(int i=0; i<26; i++) children[i] = NULL;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = root;
        
        for(auto &c: word) {
            if(!temp->children[c - 'a']) temp->children[c - 'a'] = new TrieNode();
            temp = temp->children[c - 'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        
        for(auto &c: word) {
            if(temp->children[c - 'a']) temp = temp->children[c - 'a'];
            else return false;
        }
        return temp->isEnd;
        
    }
    
    bool startsWith(string word) {
        TrieNode *temp = root;
        
        for(auto &c: word) {
            if(temp->children[c - 'a']) temp = temp->children[c - 'a'];
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */