class TrieNode {
public:
    TrieNode *child[26];
    bool isEnd;
    
    TrieNode() {
        for(int i=0; i<26; i++) child[i] = NULL;
        isEnd = false;
    }
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *temp = root;
        
        for(auto &c: word) {
            if(!temp->child[c - 'a']) temp->child[c - 'a'] = new TrieNode();
            temp = temp->child[c - 'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        return found(word, 0, temp);
    }
    
    bool found(string word, int i, TrieNode *temp) {
        if(i == word.size()) return temp->isEnd;
        
        if(word[i] == '.') {
            for(int j=0; j<26; j++) 
                if(temp->child[j] && found(word, i+1, temp->child[j])) return true;
        } else {
            if(!temp->child[word[i] - 'a']) return false;
            return found(word, i+1, temp->child[word[i] - 'a']);
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */