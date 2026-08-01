class Solution {
public:
    bool isPathCrossing(string path) {
        int i=0,j=0;
        set<pair<int,int>> vis;
        vis.insert({0,0});

        for(char c=0;c<path.size();c++){
            if(path[c]=='N'){
                i--;
            }
            else if(path[c]=='W'){
                j++;
            }
            else if(path[c]=='S'){
                i++;
            }
            else{
                j--;
            }
            if(vis.count({i,j}))
                return true;

            vis.insert({i,j});
        }
        return false;
    }
};