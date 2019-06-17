int dir[][2]={{0,1},{1,0},{-1,0},{0,-1}};
const int inf=99999999;

int solveit(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int distance[n][m];
        queue<pair<int,int> > q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1||grid[i][j]==0)
                    distance[i][j]=inf;
                 else {
                     distance[i][j]=0;
                     q.push({i,j});
                 }
            }
        }
        int x,y;

        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            int dx,dy;
            for(int k=0; k<4; ++k){
                dx=x+dir[k][0];
                dy=y+dir[k][1];
                if(dx>=0&&dx<n&&dy>=0&&dy<m&&grid[dx][dy]==1&&distance[x][y]+1<distance[dx][dy]){
                    distance[dx][dy]=1+distance[x][y];
                    q.push({dx,dy});
                }
            }

        }
        int ans=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){
                    ans=max(ans,distance[i][j]);
                }
            }
        }
        return (ans==inf?-1:ans);
}

int Solution::solve(vector<vector<int> > &A) {
    return solveit(A);
}