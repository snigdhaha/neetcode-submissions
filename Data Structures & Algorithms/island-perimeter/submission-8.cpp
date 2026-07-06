class Solution {
public:
    int bfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});

        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};
        int perimeter=0;

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newr=r+delR[i];
                int newc=c+delC[i];

                if(newr<0 || newr>=n || newc<0 || newc>=m || grid[newr][newc]==0){
                    perimeter++;
                }
                else if (!vis[newr][newc]) {
                    vis[newr][newc] = true;
                    q.push({newr, newc});
                }
            }
        }
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return bfs(i,j,vis,grid);
                }
            }
        }
        return 0;
    }
};