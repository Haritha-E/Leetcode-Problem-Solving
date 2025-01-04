void dfs(int i,int j,char** grid,int n,int m){
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1')
    return;

    grid[i][j]='0';
    dfs(i+1,j,grid,n,m);
    dfs(i,j+1,grid,n,m);
    dfs(i-1,j,grid,n,m);
    dfs(i,j-1,grid,n,m);
    
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int num=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++)
        {
            if(grid[i][j]=='1'){
                num++;
                dfs(i,j,grid,gridSize,*gridColSize);
            }
        }
    }
    return num;
}