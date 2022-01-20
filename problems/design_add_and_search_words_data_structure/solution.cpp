class TrieNode{
public:
    TrieNode *child[26];
    bool isEnd;
    
    TrieNode(){
        for(int i=0; i<26; i++) this->child[i]=NULL;
        this->isEnd = false;
    }
};

class WordDictionary {
    TrieNode *newNode;
public:
    WordDictionary() {
        newNode = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *temp = newNode;
        for(int i=0; i<word.size(); i++){
            char c = word[i]-'a';
            if(!temp->child[c]) temp->child[c] = new TrieNode();
            temp = temp->child[c];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *temp = newNode;
        return found(word, 0, temp);
    }
    
    bool found(string word, int i, TrieNode *temp){
        if(i==word.size()) return temp->isEnd;
        if(word[i]=='.'){
            for(int j=0; j<26; j++){
                if(temp->child[j] && found(word, i+1, temp->child[j])) return true;
            }
        }else{
            if(!temp->child[word[i]-'a']) return false;
            return found(word, i+1, temp->child[word[i]-'a']);
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