class Solution {
public:
    long long int mask;
    
    bool solve(vector<int> &matchsticks, int target, long long mask, int currSum, int i, int k){
        if(k==1) return true;
        
        if(currSum==target) 
                return solve(matchsticks, target, mask, 0, 0, k-1);
        
        for(int j=i; j<matchsticks.size(); j++){
            
            if((mask&(1<<j))==0 || currSum+matchsticks[j]>target) continue;
            
            mask=mask&~(1<<j);
            if(solve(matchsticks, target, mask, currSum+matchsticks[j], j+1, k)) 
                return true;
            mask=mask|(1<<j);
            
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        if(matchsticks.size()<4||sum%4) return false;
        
        mask=(1<<matchsticks.size())-1;
        sort(matchsticks.begin(), matchsticks.end());
        return solve(matchsticks, sum/4, mask, 0, 0, 4);
    }
};