class Solution {
public:
    vector<bool> visited;
    void dfs(vector<vector<int>> &rooms, int r){
        visited[r]=true;
        
        for(int i=0;i<rooms[r].size();i++){
            if(!visited[rooms[r][i]]) dfs(rooms, rooms[r][i]);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.resize(rooms.size(), false);
        
        dfs(rooms, 0);
        for(auto x : visited){
            if(!x) return false;
        }
        return true;
    }
};