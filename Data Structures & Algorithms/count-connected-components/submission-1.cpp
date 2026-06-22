class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<int>& visit, int node){
        queue<int> q;
        q.push(node);
        visit[node]=1;

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(int adjNode : adj[curr]){
                if(!visit[adjNode]){
                    visit[adjNode]=true;
                    q.push(adjNode);
                }
            }
        }

    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visit(n);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res=0;
        for(int node=0;node<n;node++){
            if(!visit[node]){
                bfs(adj,visit,node);
                res++;
            }
        }
        return res;
    }
};
