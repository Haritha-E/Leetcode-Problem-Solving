class Solution {
public:
    int sol(int i, int j, int m, int n, vector<vector<int>>& g, vector<vector<int>>& dp){
        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return g[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = g[i][j] + min(sol(i+1,j,m,n,g,dp),sol(i,j+1,m,n,g,dp));
    }
    int minPathSum(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sol(0,0,m,n,g,dp);
    }
};