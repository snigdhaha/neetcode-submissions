class Solution {
public:
    class DisjointSet {
    public:
        vector<int> rank, parent, size;

        DisjointSet(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int findUltiParent(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUltiParent(parent[node]);
        }

        void unionBySize(int u, int v) {
            int up_u = findUltiParent(u);
            int up_v = findUltiParent(v);

            if (up_u == up_v)
                return;

            if (size[up_u] < size[up_v]) {
                parent[up_u] = up_v;
                size[up_v] += size[up_u];
            } else {
                parent[up_v] = up_u;
                size[up_u] += size[up_v];
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string, int> mapMailNode;

        // Step 1: Union accounts having common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // Step 2: Store emails corresponding to each parent
        vector<vector<string>> mergedMail(n);

        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUltiParent(it.second);
            mergedMail[node].push_back(mail);
        }

        // Step 3: Prepare answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergedMail[i].empty())
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]); // account name

            for (string &mail : mergedMail[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};