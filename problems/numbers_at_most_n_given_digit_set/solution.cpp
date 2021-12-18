class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string u_lim = to_string(n);
        int arr_size = digits.size(), size = u_lim.size(), ans=0;
        
        for(int i=1;i<size;i++){
            ans += pow(arr_size, i);
        }
        
        for(int i=0;i<size;i++){
            bool startingSameNum = false;
            for(string &d :digits){
                if(d[0] < u_lim[i]) ans += pow(arr_size, size-i-1);
                else if (d[0]==u_lim[i]) startingSameNum=true;
            }
            if(!startingSameNum) return ans;
        }
        
        return ans+1;
    }
};