class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        map<int, int> m;
        for(auto i : nums) m[i]++;
        for(auto &val : m){
            int num1 = val.first, num2 = num1 - k;
            if((num1 == num2 && m[num1] > 1) || (num1 != num2) && m.count(num2)) count++;
        }
        return count;
        
    }
};