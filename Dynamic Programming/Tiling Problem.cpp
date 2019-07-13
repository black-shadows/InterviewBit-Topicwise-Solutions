int tc=0;
const int mx=1000005;
const int mod=1000000007;
long long dp[mx];

void pre(){
    if(tc)
        return;
    tc=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<mx; ++i)
        dp[i]=(dp[i-1]+dp[i-2])%mod;
}

int Solution::solve(int A) {
    pre();
    return dp[A];
}