class Solution {
private:
    int solveMem(vector<vector<char>>& matrix,vector<vector<int>>&dp,int i,int j,int n,int m){
        if(j>=m||i>=n||matrix[i][j]=='0'){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
            int right=solveMem(matrix,dp,i,j+1,n,m);
            int bottom=solveMem(matrix,dp,i+1,j,n,m);
            int diagonal=solveMem(matrix,dp,i+1,j+1,n,m);
               

       return dp[i][j]= (1+min(right,min(bottom,diagonal)));
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    // maxi=max(maxi,solve(matrix,i,j,n,m));
                    maxi=max(maxi,solveMem(matrix,dp,i,j,n,m));
                }
            }
        }
        return maxi*maxi;
    }
};