class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int lower = to_string(low).size(), upper = to_string(high).size();
        string digits = "123456789";
        
        for(int i=lower; i<=upper; i++){
            for(int j=0; j<10-i; j++){
                
                int num = stoi(digits.substr(j, i));
                if(num >= low && num <= high) ans.push_back(num);
                
            }
        }
        
        return ans;
    }
};