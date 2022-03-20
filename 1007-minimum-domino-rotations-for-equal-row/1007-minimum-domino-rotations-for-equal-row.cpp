class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(), min_rotations = INT_MAX;
        
        vector<int> faceA(7), faceB(7), same(7);
        
        
        for(int i=0; i<n; i++) {
            faceA[tops[i]]++;
            faceB[bottoms[i]]++;
            
            if(tops[i] == bottoms[i]) same[tops[i]]++;
        }
        
        for(int i=1; i<=6; i++){
            if(faceA[i] + faceB[i] - same[i] == n){
                min_rotations = min(min_rotations, min(faceA[i], faceB[i]) - same[i]);
            }  
        }
        
        return min_rotations = min_rotations == INT_MAX ? -1 : min_rotations;
    }
};