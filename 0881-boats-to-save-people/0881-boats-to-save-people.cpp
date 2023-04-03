class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int n = people.size(), l = 0, r = n-1, boatCount = 0;
        
        while(l <= r){
            int sum = people[l] + people[r];
            
            if(sum <= limit) {
                boatCount++;
                l++;
                r--;
            }else {
                boatCount++;
                r--;
            }
        }
       
        return boatCount;
    }
    
};