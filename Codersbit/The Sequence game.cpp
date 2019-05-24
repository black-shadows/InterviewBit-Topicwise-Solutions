#define mod 1000000007
long long int mexp(long long int A,long long int B){
    long long int ans=1,base=A;
    while(B){
        if(B%2!=0)
        {
            ans=(ans*base)%mod;
            B--;
        }
        else{
            base=(base*base)%mod;
            B=B/2;
        }
    }
    return ans;
}
int Solution::solve(int A, int B) {
    return mexp(A,B);
}
