struct TrieNode {
    TrieNode *next[26] = {};
    int index = -1;
    vector<int> palindromeIndexes;
};

class Solution {
    TrieNode root;
    void add(string &s, int i) {
        auto node = &root;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (isPalindrome(s, 0, j)) node->palindromeIndexes.push_back(i); 
            int c = s[j] - 'a';
            if (!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->index = i;
        node->palindromeIndexes.push_back(i); 
    }
    
    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) add(A[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < N; ++i) {
            auto s = A[i];
            auto node = &root;
            for (int j = 0; j < s.size() && node; ++j) {
                if (node->index != -1 && node->index != i && isPalindrome(s, j, s.size() - 1)) ans.push_back({ i, node->index }); 
        
                node = node->next[s[j] - 'a'];
            }
            if (!node) continue;
            for (int j : node->palindromeIndexes) {
                if (i != j) ans.push_back({ i, j });
            }
        }
        return ans;
    }
};

// class TrieNode {
// public:
//     TrieNode *child[26];
//     int index;
//     vector<int> pIndices;   //palindromeIndices
    
//     TrieNode() {
//         for(int i=0; i<26; i++) child[i] = NULL;
//         index = -1;
//     }
    
// };
// class Solution {
//     TrieNode *root;
// public:
//     bool isPalindrome(string s, int i, int j) {
//         while(i < j) {
//             if(s[i] == s[j]) i++, j--;
//             else return false;
//         }
//         return true;
//     }
    
//     void insert(string s, int i) {
//         TrieNode *curr = root;
        
//         for(int j=s.size()-1; j>=0; j--) {
//             if(isPalindrome(s, 0, j)) curr->pIndices.push_back(i);
//             if(!curr->child[s[j] - 'a']) curr->child[s[j] - 'a'] = new TrieNode();
//             curr = curr->child[s[j] - 'a'];
//         }
//         curr->index = i;
//         curr->pIndices.push_back(i);
//     }
    
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         int n = words.size();
//         vector<vector<int>> ans;
//         root = new TrieNode();
        
//         for(int i=0; i<n; i++) insert(words[i], i);
        
//         for(int i=0; i<n; i++) {
//             string w = words[i];
//             TrieNode *curr = root;
            
//             for(int j=0; j<w.size(); j++) {
//                 if(curr->index != -1 && curr->index != i && isPalindrome(w, j, w.size()-1)) {
//                     ans.push_back({i, curr->index});
//                 }
//                 curr = curr->child[w[j] - 'a'];
//                 if(!curr) break;
//             }
            
//             if(!curr) 
//                 continue;
//             for(auto &j: curr->pIndices) 
//                 if(j != i) ans.push_back({i, j});
//         }
        
//         return ans;
//     }
// };