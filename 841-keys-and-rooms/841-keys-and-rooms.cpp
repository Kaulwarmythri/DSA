class Solution {
public:
    vector<bool> visited;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        visited.resize(n, false);
        dfs(rooms, 0);
        
        for(auto i : visited) if(!i) return false;
        
        return true;
    }
    
    void dfs(vector<vector<int>> &rooms, int i) {
        visited[i] = true;
        
        for(int j=0; j<rooms[i].size(); j++) {
            if(!visited[rooms[i][j]]) dfs(rooms, rooms[i][j]);
        }
    }
};