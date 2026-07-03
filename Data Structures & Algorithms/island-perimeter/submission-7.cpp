class Solution {
public:
    int bfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,int &perimeter){
        int n=grid.size();
        int m=grid[0].size();
        
        vis[row][col]=1;

        queue<pair<int,int>> q;
        q.push({row,col});

        int delrow[]={-1,-0,1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];

                if(nr<0 || nc<0 ||nr>=n||nc>=m || grid[nr][nc]==0){
                    perimeter++;
                }
                else if(!vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int perimeter=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    perimeter=bfs(i,j,grid,vis,perimeter);
                }
            }
        }
        return perimeter;
    }
};