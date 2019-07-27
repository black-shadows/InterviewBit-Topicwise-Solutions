const int mod =1000000007;

long long modexp(long long x,long long n){
    long long r=1LL;
    while(n){
        if(n&1)
            r=(1LL*r*x)%mod;
        x=(1LL*x*x)%mod;
        n>>=1;
    }
    return r;
}

int solveit(vector<int> &a){
    int n=a.size();
    long long multiple=modexp(2LL,1LL*(n-1));
    long long ans=0;
    for(auto &it:a){
        assert(it>=1&&it<=INT_MAX);
        long long p=1LL*it*it;
        p%=mod;
        long long temp=(1LL*p*multiple)%mod;
        ans=(ans+temp);
        while(ans>=mod)
            ans-=mod;
    }
    return (int)(ans);
}

int Solution::solve(vector <int> &A){
    return solveit(A);
}