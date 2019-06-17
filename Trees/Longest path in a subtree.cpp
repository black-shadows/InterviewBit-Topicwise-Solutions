const long long mod=1000000007;

const int mx=65;
vector<int> g[mx];
long long dp[mx][mx],ans=0,k;

void dfs(int v, int par){
    dp[v][0]=1;
    for(auto &it:g[v]){
        if(it==par)
            continue;
        dfs(it, v);
        for(int i=k;i>=0;i--){
            long long val=dp[v][i];
            for(int j=0;i+j+1<=k;j++)
                dp[v][max(i, j+1)]=(dp[v][max(i, j+1)]+(1LL*val*dp[it][j])%mod)%mod;
        }
    }
    for(int i=0;i<=k;i++)
        ans=(ans+dp[v][i])%mod;
}

int doit(int A,vector<int> &B,vector<int> &C,int D){
    for(int i=0; i<=A; ++i)
        g[i].clear();
    memset(dp,0,sizeof dp);
    k=D;
    for(int i=0; i<B.size(); ++i){
        g[B[i]].push_back(C[i]);
        g[C[i]].push_back(B[i]);
    }
    ans=0;
    dfs(1,1);
    return ans;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C, int D) {
    return doit(A,B,C,D);
}