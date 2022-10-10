class Solution {
public:
    vector<vector<int>> dirsB = {{1, 1},  {-1, 1},  {1, -1}, {-1, -1}};
    vector<vector<int>> dirsR = {{0, 1},  {0, -1},  {1, 0}, {-1, 0}};
    
    bool isValid(int x, int y) {
        if (x < 0 || y < 0 || x >= 8 || y >= 8) 
            return false;
        
        return true;
    }
    
    void fill(int i, vector<vector<vector<int>>> & moves, int x, int y, vector<vector<int>> & dirs) {
         for (int k = 0; k < 4; k++) {
            auto & dir = dirs[k];
            int ii = x + dir[0], jj = y + dir[1];
            int t = 1;
            while (isValid(ii, jj)) {
                moves[i].push_back({dir[0], dir[1], t}); // store the x y dir and how long it took to get its final destination.
                
                ii += dir[0];
                jj += dir[1];
                t++;
            }
        }
    }
    
    bool check(vector<int> pos1, vector<int> & nPos1, vector<int> pos2, vector<int> & nPos2) {
        // simulation, move two pieces, check if they clash for every second
        int t1 = nPos1.back(), t2 = nPos2.back();
        for (int i = 1; i <= max(t1, t2); i++) {
            if (i <= t1) {
                pos1[0] += nPos1[0];
                pos1[1] += nPos1[1];
            }
            
            if (i <= t2) {
                pos2[0] += nPos2[0];
                pos2[1] += nPos2[1];
            }
            
            if (pos1 == pos2)
                return false;
        }
        return true;
    }
    
    void dfs(int curr, vector<vector<int>> & newPos, vector<vector<int>>& pos, vector<vector<vector<int>>> & moves, int & ans) {
        if (curr >= moves.size()) {
            ans++;
            return;
        } 
        
        for (auto & move : moves[curr]) {
            bool ok = true;
            for (int i = 0; i < newPos.size(); i++) {
                if (!check(pos[i], newPos[i], pos[curr], move)) {
                    ok = false;
                    break;
                }
            }
            
            if (!ok) {
                continue;
            }
            newPos.push_back(move);
            dfs(curr+1, newPos, pos, moves, ans);
            newPos.pop_back();
        }
    }
    
    int countCombinations(vector<string>& pieces, vector<vector<int>>& pos) {
        int n = pieces.size();
        vector<vector<vector<int>>> moves(n);
        
        for (auto & p : pos) {
            p[0]--;
            p[1]--;
        }
        
        for (int i = 0; i < n; i++) {
            int x = pos[i][0], y = pos[i][1];
            moves[i].push_back({0, 0, 0});
            if (pieces[i] == "rook") {
                fill(i, moves, x, y, dirsR);
            } else if (pieces[i] == "bishop") {
                fill(i, moves, x, y, dirsB);
            } else {
                fill(i, moves, x, y, dirsB);
                fill(i, moves, x, y, dirsR);
            }
        }
        vector<vector<int>> newPos;
        int ans = 0;
        dfs(0, newPos, pos, moves, ans);
        return ans;
    }
};