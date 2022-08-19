class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> tails, counts;
        
        for(auto &num: nums) counts[num]++;
        
        for(auto &i: nums) {
            if(!counts[i]) continue;
            
            if(tails[i-1] > 0) {
                counts[i]--;
                tails[i-1]--;
                tails[i]++;
            } else if(counts[i+1] > 0 && counts[i+2] > 0) {
                counts[i]--;
                counts[i+1]--;
                counts[i+2]--;
                tails[i+2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};