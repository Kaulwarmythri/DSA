class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftC, vector<int>& rightC) {
        vector<int> parentFreq(n, 0);
        
        for(int i=0; i<n; i++) {
            if(leftC[i] != -1 && ++parentFreq[leftC[i]] > 1 || rightC[i] != -1 && ++parentFreq[rightC[i]] > 1)
                return false;
        }
        
        int root = -1;
        for(int i=0; i<n; i++) {
            if(!parentFreq[i]) {
               if(root == -1) root = i;
                else return false; 
            }
        }
        
        return countNodes(root, leftC, rightC) == n;
        
    }
    
    int countNodes(int root, vector<int> &leftC, vector<int> &rightC) {
        if(root == -1) return 0;
        return 1 + countNodes(leftC[root], leftC, rightC) + countNodes(rightC[root], leftC, rightC);
    }
};