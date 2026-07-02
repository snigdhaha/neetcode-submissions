class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=1;
                    int perimeter=0;

                    while(!q.empty()){
                        int x= q.front().first;
                        int y=q.front().second;
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nr=x+delRow[k];
                            int nc=y+delCol[k];

                            if(nr<0 || nc<0 || nr>=n || nc>=m || grid[nr][nc]==0){
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
            } 
        }
        return 0;
    }
};