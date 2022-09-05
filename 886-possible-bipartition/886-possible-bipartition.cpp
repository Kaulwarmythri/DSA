class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		vector<int> G[n + 1];
        
		for (auto i : dislikes) {
			G[i[0]].push_back(i[1]);
			G[i[1]].push_back(i[0]);
		}
		vector<int>color(n + 1, -1);
        
		for (int i = 1; i <= n; i++) {
			if (color[i] == -1) {
				if (!possibleToColor(i, 1, G, color))
                    return false;
			}
		}
		return true;
	}

	bool possibleToColor(int i, int c, vector<int> G[], vector<int>&color) {
		color[i] = c;
		for (auto child : G[i]) {
			if (color[child] == -1) 
                possibleToColor(child, 1 - c, G, color);
			else if (color[child] == color[i]) 
				return false;
		}
		return true;
	}
};