class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        
        vector<vector<string>> ans;
        
        for(auto &path: paths) {
            stringstream ss(path);
            string dir, s, filename, content;
            
            getline(ss, dir, ' ');
            while(getline(ss, s, ' ')) {
                filename = dir + '/' + s.substr(0, s.find('('));
                content = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                files[content].push_back(filename);
            }
        }
        
        for(auto &f: files) {
            if(f.second.size() > 1) {
                ans.push_back(f.second);
            }
        }
        return ans;
    }
};

