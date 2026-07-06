class Solution {
public:
int bfs(int row, int col,vector<vector<int>> &vis,vector<vector<int>> &grid) {

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>> q;
    q.push({row,col});
    vis[row][col] = 1;

    int area = 1;

    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};

    while(!q.empty()){
        auto [row,col] = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                area++;
                q.push({nrow,ncol});
            }
        }
    }

    return area;
}


    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int maxi = 0;

    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){

            if(!vis[row][col] && grid[row][col]==1){
                int area = bfs(row,col,vis,grid);
                maxi = max(maxi, area);
            }
        }
    }

    return maxi;
    }
};
