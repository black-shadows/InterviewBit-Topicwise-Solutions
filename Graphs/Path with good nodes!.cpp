vector<vector<int>> adj;

int dfs(int u,int p,int c,vector<int> &A){
    int ans=0;
    int children=0;
    for(int v: adj[u]){
        if(v!=p){
            if(A[u-1]==0){
                ans+=dfs(v,u,c,A);
            }else{
                ans+=dfs(v,u,c-1,A);
            }
            children++;
        }
    }

    if(children==0){
        if(c>=1 || (c==0 && A[u-1]==0))return 1;
        else return 0;
    }
    
    return ans;
    
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    adj.assign(100005,vector<int>());
    
    int n=A.size();
    for(int i=0;i<n-1;i++){
        int a=B[i][0];
        int b=B[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    return dfs(1,-1,C,A);
}
