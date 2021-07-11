class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(), strs.end());
        int n = strs.size(), i;
        string first = strs[0];
        string last = strs[n-1];
        string result = "";
        
        if(n==0){return result;}
        
        int limit = min(first.length(), last.length());
        
        for(i=0;i<limit;i++){
            if(first[i]==last[i]){
                result += first[i];
            }   
            else{
                break;
            }

        }
        
        return result;
        
    }
};