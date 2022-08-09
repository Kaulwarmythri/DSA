class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftc, vector<int>& rightc) {
        vector<int> parentFreq(n);
        
        for(int i=0; i<n; i++) {
            if((leftc[i] != -1 && ++parentFreq[leftc[i]] > 1) || rightc[i] != -1 && ++parentFreq[rightc[i]] > 1) 
                return false;
        }
        
        int root = -1;
        
        for(int i=0; i<n; i++) {
            if(!parentFreq[i]) {
                if(root == -1) root = i;
                else return false;
            }
        }

        return countNodes(root, leftc, rightc) == n;
    }
    
    int countNodes(int root, vector<int> &leftc, vector<int> &rightc) {
        if(root == -1) return 0;
        return 1 + countNodes(leftc[root], leftc, rightc) + countNodes(rightc[root], leftc, rightc);
    }
};