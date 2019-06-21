int dir[][2]={{0,1},{1,0},{-1,0},{0,-1}};
int tc=0;

int visited[105][105];

bool check(int i,int j,int n,int m,vector<vector<int> > &A){
    return (i>=0 && i<n && j>=0 && j<m && (A[i][j]==1) && visited[i][j]!=tc);
}

void dfs(int i,int j,int n,int m,vector<vector<int> > &A){
    visited[i][j]=tc;
    int di,dj;
    for(int k=0; k<4; ++k){
        di=i+dir[k][0];
        dj=j+dir[k][1];
        if(check(di,dj,n,m,A))
            dfs(di,dj,n,m,A);
        }
}


int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    ++tc;
    int numberofislands=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
                if(A[i][j]==1 && visited[i][j]!=tc){
                    dfs(i,j,n,m,A);
                    ++numberofislands;
                }
            }
        }
    return numberofislands;
}