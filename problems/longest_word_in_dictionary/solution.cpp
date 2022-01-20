class TrieNode{
public:
    TrieNode *child[26];
    bool isEnd;
    
    TrieNode(){
        this->isEnd = false;
        for(int i=0; i<26; i++) this->child[i] = NULL;
    }
};

class Solution {
private:
    TrieNode *newNode;
    //To check is all the prefixes of a word exist ie; if "temp->isEnd" for all the letters/ nodes of the word
    bool AllPrefixesExist(string word){
        TrieNode *t = newNode;
        bool flag = true;
        
        for(auto &w : word){
            if(t->child[w-'a']){
                t = t->child[w-'a'];
                flag = flag & t->isEnd;
            }else return false;
        }
        return flag;
    }
    
    //Inserts a word into trie & sets isEnd of last node to true indicating that it is the end of the word
    void insert(string s){
        TrieNode *temp = newNode;
        for(auto l : s){
            if(!temp->child[l-'a']) temp->child[l-'a'] = new TrieNode();
            temp = temp->child[l-'a'];
        }
        temp->isEnd = true;
    }
    
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        newNode = new TrieNode();
        
        for(auto &x : words) insert(x);
        
        string longest = "";
        for(auto &x : words){
            
            if(AllPrefixesExist(x)){ 
                //If all the prefixes of a word exist & the word is greater than the prev longest or it's lexiographically smaller, make it longest
                if((x.size() > longest.size()) ||
                   (x.size() == longest.size() && x < longest)) 
                    longest = x;
            }
        }
        if(longest == "") return "";
        return longest;
    }
};



