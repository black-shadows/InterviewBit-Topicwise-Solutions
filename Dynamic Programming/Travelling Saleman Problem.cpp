int dp[10][(1<<10)];
int minCost(vector<vector<int> > &B,int A,int u,int mask){
    if(mask==0){
        return B[u][0];
    }
    int ans=INT_MAX;
    if(dp[u][mask]!=-1)return dp[u][mask];
    for(int i=0;i<A;i++){
        if(mask&(1<<i)){
            ans=min(ans,minCost(B,A,i,mask^(1<<i))+B[u][i]);
        }
    }
    return dp[u][mask]=ans;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    if(A==1)return 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<(1<<10);j++)dp[i][j]=-1;
    }
    return minCost(B,A,0,((1<<A)-1)^1);
}
