class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& P) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

    for(auto it:P){
        adj[it[1]].push_back(it[0]); //opp order
    }

   

    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);

        //node is in toposort-remmove from indegree
        for(auto it:adj[node]){  //adj[node] contains all the vertices that node points to.
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    if(topo.size()==n) return topo;

    return {};
    }
};
