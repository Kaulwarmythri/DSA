class TrieNode {
public:
    TrieNode *child[27];
    int index = -1;
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string s, int i) {
        TrieNode *temp = root;
        
        for(auto c : s) {
            if(!temp->child[c - 'a']) temp->child[c - 'a'] = new TrieNode();
            temp = temp->child[c - 'a'];
            temp->index = i;
        }
    }
    
    int search(string s) {
        TrieNode *temp = root;
        
        for(auto c : s) {
            if(!temp->child[c - 'a']) return -1;
            
            temp = temp->child[c - 'a'];
        }
        return temp->index;
    }
};

class WordFilter {
    Trie *root;
public:
    WordFilter(vector<string>& words) {
        root = new Trie();
        
        int n = words.size();
        string s = "";
        int index = 0;
        
        for(int i=0; i<n; i++) {
            s = '{' + words[i];
            root->insert(s, index);
            
            for(int j=0; j<words[i].size(); j++) {
                s = words[i].substr(j) + '{' + words[i];
                root->insert(s, index);
            }
            index++;
        }
    }
    
    int f(string prefix, string suffix) {
        string s = suffix + "{" + prefix;
        return root->search(s);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */