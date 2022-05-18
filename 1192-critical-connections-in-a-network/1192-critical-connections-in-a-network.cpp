class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc = vector<int>(n);
        low = vector<int>(n);
        for (auto c : connections) {
            edgeMap[c[0]].push_back(c[1]);
            edgeMap[c[1]].push_back(c[0]);
        }
        dfs(0, -1);
        return ans;
    }
    void dfs(int curr, int prev) {
        disc[curr] = low[curr] = time++;
        for (int next : edgeMap[curr]) {
            if (disc[next] == 0) {
                dfs(next, curr);
                low[curr] = min(low[curr], low[next]);
            } else if (next != prev)
                low[curr] = min(low[curr], disc[next]);
            if (low[next] > disc[curr]) 
                ans.push_back({curr, next});
        }
    }
private:
    vector<int> disc{0}, low{0};
    int time = 1;
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> edgeMap;
};