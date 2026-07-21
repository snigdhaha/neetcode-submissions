class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &it : prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        // pre[i] = all prerequisites of course i
        vector<unordered_set<int>> pre(numCourses);

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                // node itself is a prerequisite of nxt
                pre[it].insert(node);
                // all prerequisites of node are also prerequisites of nxt
                for (int x : pre[node]) {
                    pre[it].insert(x);
                }

                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        for(auto &it:queries){
            ans.push_back(pre[it[1]].count(it[0]));
        }

        return ans;
    }
};