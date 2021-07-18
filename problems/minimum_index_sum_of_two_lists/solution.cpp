class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> m;
        vector<string> v;
        int min = INT_MAX;
        for(int i=0;i<list1.size();i++){
            m[list1[i]] = i;
        }
        for(int i=0;i<list2.size();i++){
            if(m.count(list2[i])!=0){
                if(i + m[list2[i]] < min){
                    min = i + m[list2[i]];
                    v.clear();
                    v.push_back(list2[i]);
                }else if(i + m[list2[i]]==min){
                    v.push_back(list2[i]);
                }
            } 
        }
        return v;
    }
};