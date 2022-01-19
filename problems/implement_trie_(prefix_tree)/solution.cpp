class TrieNode{    
public:
    TrieNode *child[26];
    bool end;    
    
    TrieNode(){
        this->end = false;
        for(int i=0; i<26; i++) this->child[i] = NULL;
    }
};

class Trie{
    TrieNode *newNode;
public:
    Trie(){
        newNode = new TrieNode();
    }
    
    void insert(string word){
        int len = word.size();
        TrieNode *temp = newNode;
        
        for(int i=0; i<len; i++){
            char c = word[i]-'a';
            if(!temp->child[c]) temp->child[c] = new TrieNode();
            temp = temp->child[c];
        }
        temp->end=true;
    }
    
    bool search(string word){
        TrieNode *temp = newNode;
        for(int i=0; i<word.size(); i++){
            char c = word[i] - 'a';
            if(!temp->child[c]) return false;
            temp = temp->child[c];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix){
        TrieNode *temp = newNode;
        
        for(int i=0; i<prefix.size(); i++){
            char c = prefix[i]-'a';
            if(!temp->child[c]) return false;
            temp = temp->child[c];
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