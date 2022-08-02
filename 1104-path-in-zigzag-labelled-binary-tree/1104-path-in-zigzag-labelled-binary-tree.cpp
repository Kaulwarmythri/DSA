class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int height = log2(label);
        
        ans.push_back(label);
        
        while(height > 0) {
            int dist = (label - pow(2, height)) / 2;
            label = pow(2, height) - 1 - dist;
            ans.push_back(label);
            
            height--;
        }
        
        return vector<int>(ans.rbegin(), ans.rend());
        
    }
};