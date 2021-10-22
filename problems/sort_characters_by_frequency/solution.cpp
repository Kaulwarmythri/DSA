class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        multimap<int, char, greater<int>> mmp;
        for(unsigned int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        
        int i, j=0;
        for(auto it=m.begin();it!=m.end();it++){
            mmp.insert(make_pair(it->second, it->first));
        }  
        for(auto it=mmp.begin();it!=mmp.end();it++){
            for(i=0;i<it->first;i++){
               s[j++]=it->second; 
            }
        }
        return s;
    }
};