class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int left = f(i,j-1,m,n,dp);
        int up = f(i-1,j,m,n,dp);

        return dp[i][j]=left+up;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //return f(m-1,n-1,m,n,dp);


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int left=0;
                int up=0;

                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                if(j>0) left = dp[i][j-1];
                if(i>0) up =dp[i-1][j];

                dp[i][j]=left+up;
            }
        }
        return dp[m-1][n-1];
    }
};
