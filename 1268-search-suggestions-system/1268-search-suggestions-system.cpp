class TrieNode {
public:
    TrieNode *children[26] = {};
    bool isEnd = false;
};

class Trie {
public:
    TrieNode *root;
    
    Trie() {
        root = new TrieNode();   
    }
    
    void insert(string s) {
        TrieNode *temp = root;
        for(auto c : s) {
            if(!temp->children[c - 'a']) temp->children[c - 'a'] = new TrieNode();
            temp = temp->children[c - 'a'];
        }
        temp->isEnd = true;
    }
    
    void dfsWithPrefix(TrieNode *curr, string pre, vector<string> &res) {
        if(res.size() == 3) return;
        
        if(curr->isEnd) res.push_back(pre);
        
        for(auto w='a'; w <= 'z'; w++) {
            if(curr->children[w - 'a']) {
                pre += w;
                dfsWithPrefix(curr->children[w - 'a'], pre, res);
                pre.pop_back();
            }
        }
    }
    
    void startsWith(string pre, vector<string> &res) {
        TrieNode *temp = root;
        
        for(auto c : pre) {
            if(temp->children[c - 'a']) {
                temp = temp->children[c - 'a'];
            }
            else return;
        }
        dfsWithPrefix(temp, pre, res);
    }
    
    
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        Trie *root = new Trie();
        vector<vector<string>> ans;
        
        for(auto p : products) {
            root->insert(p);
        }
        
        string prefix = "";
        for(auto c : search) {
            prefix += c;
            vector<string> res;
            root->startsWith(prefix, res);
            
            ans.push_back(res);
        }
        return ans;
    }
};