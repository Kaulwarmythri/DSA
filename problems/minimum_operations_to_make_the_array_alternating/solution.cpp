class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), oddCnt = 0, evenCnt = 0;
        if(n == 1) return 0;
        if(n == 2) return nums[0] == nums[1] ? 1 : 0;
        unordered_map<int, int> odd, even;
        
        for(int i=0; i<n; i++){
            if(i&1) odd[nums[i]]++, oddCnt++;
            else even[nums[i]]++, evenCnt++;
        }
        priority_queue<pair<int, int>> oddQ, evenQ;

        for(auto it = odd.begin(); it != odd.end(); it++) 
            oddQ.push({it->second, it->first});
        for(auto it = even.begin(); it != even.end(); it++) 
            evenQ.push({it->second, it->first});
        
        int oddVal = oddQ.top().first, oddKey = evenQ.top().second;
        int evenVal = evenQ.top().first, evenKey = oddQ.top().second;
            
        if(oddKey != evenKey) return n - oddVal - evenVal;
        else{
            if(evenVal > oddVal){
                oddQ.pop();
                if(!oddQ.size()) return n - evenVal;
                return n - evenVal - oddQ.top().first;
            }
            else{
                evenQ.pop();
                if(!evenQ.size()) return n - oddVal;
                return n - oddVal - evenQ.top().first;
            }
        }
        return 0;
        
    }
};
