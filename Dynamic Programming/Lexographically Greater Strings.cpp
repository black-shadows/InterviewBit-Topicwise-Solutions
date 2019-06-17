const long long MOD =1000000007;

long long dp[3][2005][2005];

int doit(int n,int k,string &s){
for(int i=0; i<3;++i)
for(int j=0; j<=n; ++j)
for(int pp=0; pp<=k; ++pp)
dp[i][j][pp]=0;
dp[1][0][0] = 1;
for(int i=1;i<=n;i++){
for(int j=0;j<=k;j++){
long long p_sum = 0;
for(int k=0;k<3;k++)
p_sum += dp[k][i-1][j];
p_sum %= MOD;
dp[0][i][j]=p_sum;
dp[1][i][j]=(s[i-1]-'a')*p_sum%MOD;
dp[2][i][j]=0;
long long add = n-i+1;
for(int prev=i;prev>0;prev--){
if(add>j) break;
dp[2][i][j]+=(26-(s[i-1]-'a'+1))*(dp[1][prev-1][j-add]+dp[2][prev-1][j-add])%MOD;
if(dp[2][i][j]>=MOD)
dp[2][i][j]-=MOD;
add += n-i+1;
}
}
}

long long ans = 0;
for(int i=0;i<3;i++)
    ans += dp[i][n][k];
ans %= MOD;
return (int)(ans); }
int Solution::solve(int A, int B, string C) {
return doit(A,B,C);
}