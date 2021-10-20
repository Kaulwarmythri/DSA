class Solution {
public:
    int firstUniqChar(string s) {
        
         unordered_map<char, int> table {};
        int len = s.length();
        for (int index = 0; index < len; ++index)
        {
            char ch = s.at(index);
            auto itr = table.find(ch);
            
            if (itr == table.end())
            {
                table.insert({ch, index});
            }
            else
            {
                itr->second = len;
            }
        }
        
        int minIndex = len;
            
        for (auto item : table)
        {
            //cout << item.first << ", " << item.second << endl;
            minIndex = min(minIndex, item.second);
        }
        
        
        if (minIndex == len)
            return -1;
        
        return minIndex; 
    }
};