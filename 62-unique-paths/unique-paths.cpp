class Solution {
public:
    int sol(int i,int j,int m,int n,vector<vector<int>>&db)
    {
        if(i>=m || j>=n) return 0;
        if(i==(m-1) && j==(n-1)) return 1;
        if(db[i][j]!=-1) return db[i][j];
        return db[i][j]=sol(i+1,j,m,n,db)+sol(i,j+1,m,n,db);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> db(m, vector<int>(n, -1));
        return sol(0,0,m,n,db); 
        
    }
};