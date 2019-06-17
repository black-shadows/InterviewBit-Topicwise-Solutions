void explore(int i, int j, int n, int m, unordered_set<int> visited, int &count, int k, vector<vector<int>>& grid){
    if(i<0||i>=n||j<0||j>=m||visited.count(i*m+j)>0||grid[i][j]==-1)
        return;
    if(grid[i][j]==2){
        if(visited.size()==k)
            count++;
    }
    visited.insert(i*m+j);
    explore(i+1,j,n,m,visited,count,k,grid);
    explore(i,j+1,n,m,visited,count,k,grid);
    explore(i-1,j,n,m,visited,count,k,grid);
    explore(i,j-1,n,m,visited,count,k,grid);;
}

int Solution::solve(vector<vector<int> > &grid) 
{
    
    int k=1;
    int n =grid.size();
    int m=grid[0].size();
    for(auto i:grid){
        for(auto j:i)
            if(j==0)
                k++;
    }
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                unordered_set<int> visited;
                explore(i,j,n,m,visited,count,k,grid);
            }
        }
    }
    return count;
    
}
