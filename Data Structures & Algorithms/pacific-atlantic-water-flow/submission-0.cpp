class Solution {
public:

    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis) {

        int m = heights.size();
        int n = heights[0].size();

        vis[r][c] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               !vis[nr][nc] &&
               heights[nr][nc] >= heights[r][c]) {

                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        // Pacific (top row)
        for(int j = 0; j < n; j++)
            dfs(0, j, heights, pac);

        // Pacific (left col)
        for(int i = 0; i < m; i++)
            dfs(i, 0, heights, pac);

        // Atlantic (bottom row)
        for(int j = 0; j < n; j++)
            dfs(m - 1, j, heights, atl);

        // Atlantic (right col)
        for(int i = 0; i < m; i++)
            dfs(i, n - 1, heights, atl);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};