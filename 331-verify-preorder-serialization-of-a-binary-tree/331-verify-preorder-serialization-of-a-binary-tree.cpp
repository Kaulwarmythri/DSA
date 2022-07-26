class Solution {
public:
    bool isValidSerialization(string preorder) {
        int nodes = 1;
        stringstream ss(preorder);
        string curr;
        
        while(getline(ss, curr, ',')) {
            nodes--;
            
            if(nodes < 0) return false;
            if(curr != "#") nodes += 2;
        }
        return nodes == 0;
    }
};