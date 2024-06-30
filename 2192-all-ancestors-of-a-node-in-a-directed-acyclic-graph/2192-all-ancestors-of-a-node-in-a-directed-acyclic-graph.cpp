class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& E) {
        vector<vector<int>> ans(n); 
        vector<int> inDegree(n, 0);  
        vector<vector<int>> adj(n);   
        vector<set<int>> ancestors(n); 

        for (auto& e : E) {
            inDegree[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }

        queue<int> pq;
        for (int i = 0; i < n; ++i) 
            if (inDegree[i] == 0) 
                pq.push(i);

        while (!pq.empty()) {
            int node = pq.front();
            pq.pop();

            for (int it : adj[node]) {
                ancestors[it].insert(node);
                ancestors[it].insert(ancestors[node].begin(), ancestors[node].end());

                inDegree[it]--;
                if (inDegree[it] == 0) 
                    pq.push(it);
            }
        }

        for (int i = 0; i < n; ++i) {
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return ans;
    }
};