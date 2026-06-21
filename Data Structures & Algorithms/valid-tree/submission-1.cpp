class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // Tree must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        dfs(0, adj, vis);

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }

        return true;
    }
};