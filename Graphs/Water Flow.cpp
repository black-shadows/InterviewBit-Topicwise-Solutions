int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0}; 
int ans = 0;
void dfs(int i, int j, vector<vector<int> > &A, vector<vector<bool> > &blue,vector<vector<bool> > &red ){
    if(red[i][j]){ 
        ans++;
    }    
    for(int next = 0; next<4; next++){
        
        int x = i + dx[next];
        int y = j + dy[next];
        
        if(x>=0 and y>=0 and x<A.size() and y<A[0].size() ){
    
            if( A[i][j]<=A[x][y] and blue[x][y]==0){
                blue[x][y] = 1;
                dfs(x,y, A, blue, red);
            }
                
        }
    }
    
}
 
int Solution::solve(vector<vector<int> > &A) {
    vector<vector<bool> > blue(A.size(), vector<bool>(A[0].size(),0));
    vector<vector<bool> > red(A.size(), vector<bool>(A[0].size(),0));
    ans = 0;
    int N = A.size();
    int M = A[0].size();
    for(int i=0; i<N; i++){
        if(blue[i][0] == 0){
            blue[i][0] = 1;
            dfs( i,0, A, blue, red);
        }
    }
    
    for(int i=0; i<M; i++)
        if(blue[0][i] == 0){
            blue[0][i] = 1;
            dfs(0, i, A, blue, red);
        }
    
    for(int i=0; i<M; i++){
        if(red[N-1][i]==0){
            red[N-1][i] = 1;
            dfs(N-1, i, A, red , blue );
        }
    }
    
    for(int i=0; i<N; i++){
        if(red[i][M-1] == 0){
            red[i][M-1] = 1;
            dfs(i, M-1, A, red, blue);
        }
    }
    return ans;
}