#define ll long long
#define MOD 1000000007

ll powmod(ll base,ll exponent)
{
    if(exponent<0) exponent+=MOD-1;
    ll ans=1;
    while(exponent){
        if(exponent&1)ans=(ans*base)%MOD;
        base=(base*base)%MOD;
        exponent/=2;
    }
    return ans;
}

int Solution::solve(int A, vector<int> &B) {
    sort(B.begin(),B.end());
    long long fact[10000];
    fact[0] = 1;
    #define mod 1000000007
    for(int i = 1;i < 10000;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    vector<long long> vs;
    long long n = B.size();
    vs.push_back(B[0]-1);
    for(int i = 1;i < n;i++){
        vs.push_back(B[i]-B[i-1]-1);
    }
    vs.push_back(A-B[n-1]);
    long long ans = 1;
    long long sum = 0,pro = 1;
    for(int i = 0;i < vs.size();i++){
        if(vs[i] == 0) continue;
        if(i != 0 && i != vs.size()-1) ans = (ans*powmod(2,vs[i]-1))%mod;
        sum = (sum + vs[i])%mod;
        pro = (pro*fact[vs[i]])%mod;
    }
    ans = (ans * fact[sum])%mod;
    ans = (ans * powmod(pro,mod-2))%mod;
    return ans;
}
