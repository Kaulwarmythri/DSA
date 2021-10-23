class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(int i=0;i<magazine.size();i++){
            m[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            auto p = m.find(ransomNote[i]);
            if(p == m.end()){
                return false;
            }else{
                p->second--;
                if(p->second < 0) return false;
            } 
        }
        return true;
    }
};