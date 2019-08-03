int solveit(int N, int A, int B) {
    long long ab=(1LL*A*B)/__gcd(A,B);
    long long l=1LL,r=(long long)(1e18),m,ans;
    long long mod=1000000007;
    while(l<=r){
        m=(l+r)>>1;
        long long temp=m/A+m/B-m/ab;
        if(temp>=N){
            ans=m;
            r=m-1;
        }
        else
            l=m+1;
        }
    return (int)(ans%mod);
}

int Solution::solve(int A, int B, int C) {
    return solveit(A,B,C);
}
