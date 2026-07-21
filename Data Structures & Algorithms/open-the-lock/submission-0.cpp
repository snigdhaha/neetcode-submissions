class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if(dead.count("0000")) return -1;
        

        queue<pair<string,int>> q;
        q.push({"0000",0});
        unordered_set<string> vis;
        vis.insert("0000");

        while(!q.empty()){
            string lock=q.front().first;
            int steps=q.front().second;
            q.pop();

            if(lock==target) return steps;

            for(int i=0;i<4;i++){

                char original = lock[i];

                // Rotate forward
                lock[i] = (original-'0'+1)%10 + '0';
                if(!dead.count(lock) && !vis.count(lock)){
                    vis.insert(lock);
                    q.push({lock,steps+1});
                }

                // Rotate backward
                lock[i] = (original-'0'+9)%10 + '0';
                if(!dead.count(lock) && !vis.count(lock)){
                    vis.insert(lock);
                    q.push({lock,steps+1});
                }
                lock[i]=original;
            }
        }
        return -1;
    }
};