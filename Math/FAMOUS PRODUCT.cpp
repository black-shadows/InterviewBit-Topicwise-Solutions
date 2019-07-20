const int N =1000005;
int mark[N];
const long long mod =1000000007;


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

void segmentedsieve(int a,int b){
    for(int i=a; i<b+1; ++i)
        mark[i-a]=2;
    if(a==1)
        mark[0]=1;
    for(int i=2LL; i*i<=b; ++i){
        for(int j=((a-1)/i+1)*i; j<=b; j+=i){
            if(j<i*i)
                continue;
            if(j==i*i)
                mark[j-a]+=1;
            else
                mark[j-a]+=2;
        }
    }
}


int Solution::solve(vector <int> &A){
    int mx=INT_MIN,mn=INT_MAX;
    for(auto &it:A){
        assert(it<=INT_MAX&&it>=1);
        mx=max(mx,it);
        mn=min(mn,it);
    }
    int n=A.size();
    assert(n>=1&&n<=100000);
    assert(mx-mn<=1000000);
    segmentedsieve(mn,mx);
    long long ans=1LL;
    long long coun=0;
    for(int i=0; i<n; ++i){
        if(mark[A[i]-mn]==2){
            A[i]%=mod;
            ans=(1LL*ans*(A[i]%mod+1))%mod;
            ++coun;
        }
    }
    ans=(1LL*ans*modexp(2LL,n-coun))%mod;
    return (int)(ans);
    
}