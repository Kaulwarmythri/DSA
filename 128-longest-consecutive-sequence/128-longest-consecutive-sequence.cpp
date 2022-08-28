class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        int longest = 0;
        
        for(auto &num: nums) {
            int curr_longest = 1;
            for(int j=1; s.count(num - j); j++) s.erase(num-j), curr_longest++;
            
            for(int j=1; s.count(num + j); j++) s.erase(num+j), curr_longest++;
            
            longest = max(longest, curr_longest);
        }
        return longest;
    }
};