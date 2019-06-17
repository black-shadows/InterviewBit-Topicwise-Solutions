const int inf = 99999999;
int dir[][2]={{0,1},{1,0},{0,-1},{-1,0}};

vector<vector<int> > solveit(vector<vector<int> > A){
    int n=A.size();
    int m=A[0].size();
    queue<pair<int,int> > q;
    vector<vector<int> > distance(n,vector<int>(m,inf));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(A[i][j]==1){
                distance[i][j]=0;
                q.push({i,j});
            }
        }
    }
    assert(q.empty()==false);
    int x,y;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        int dx,dy;
        for(int k=0; k<4; ++k){
            dx=x+dir[k][0];
            dy=y+dir[k][1];
            if(dx>=0&&dx<n&&dy>=0&&dy<m&&distance[dx][dy]>distance[x][y]+1){
                distance[dx][dy]=distance[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
    return distance;
}


vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    return solveit(A);
}
