class Solution {
public:
    int secondHighest(string s) {
        int max=-1, smax=-1;
        for(auto c : s){
            if(isdigit(c)){
                int n=c-'0';
                if(n>max){
                    smax=max;
                    max=n;
                }else if(n > smax && n < max) smax=n;
            }
        }
        return smax;
    }
};