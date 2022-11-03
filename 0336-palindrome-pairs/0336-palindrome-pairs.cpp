class TrieNode {
public:
    TrieNode *child[26]={NULL};
    int index = -1;
    vector<int> pIndices;   //palindromeIndices
};

class Solution {
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    void insert(string &s, int i) {
        TrieNode *cur = root;
        for (int j = s.size()-1; j >= 0; j--) {
            int c = s[j] - 'a';
            if (!cur->child[c]) cur->child[c] = new TrieNode();
            
            if (isPalindrome(s, 0, j)) cur->pIndices.push_back(i);
            cur = cur->child[c];
        }
        cur->pIndices.push_back(i);
        cur->index = i;
    }

public:
    TrieNode *root;
    
    vector<vector<int>> palindromePairs(vector<string> &A) {
        int n = A.size();
        root = new TrieNode();
        for (int i = 0; i < n; i++) insert(A[i], i);
        
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            TrieNode *curr = root;
            string s = A[i];
            for (int j = 0; j < s.size(); j++) {
                if (curr->index != -1 && curr->index != i && isPalindrome(s, j, s.size()-1))
                    ans.push_back({i, curr->index});
                
                curr = curr->child[s[j] - 'a'];
                if (!curr) break;
            }
            if (!curr) continue;
            for (auto &j: curr->pIndices) {
                if (i == j) continue;
                ans.push_back({i, j});
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