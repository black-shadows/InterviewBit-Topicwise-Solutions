typedef long long LL;
LL fast_pow(LL a , LL b , LL mod){
    LL res = 1;
    while(b){
        if(b & 1){
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

int Solution::solve(vector<string> &A) {
    int n=(int)A.size();
    vector<long long int>v;
    for(int i=0;i<n;i++)
    {
        int fl=1;
        for(int j=1;j<A[i].length();j++)
        {
            if(A[i][j]!=A[i][j-1])
            {
                fl=0;
                break;
            }
        }
        if(fl)v.push_back(1);
        else
        {
            long long ct=0,p=0,r=1,l=A[i].length();
            while(true)
            {
                p=(p+r)%l;
                r++;
                ct++;
                if(p==0)break;
            }
            v.push_back(ct);
        }
    }
    long long int ans=1;
    const int MOD=1000000007;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        for(int j=2;j*1LL*j<=v[i];j++)
        {
            int ct=0;
            while(v[i]%j==0)
            {
                ct++;
                v[i]/=j;
            }
            if(ct)mp[j]=max(mp[j],ct);
        }
        if(v[i]>1)mp[v[i]]=max(mp[v[i]],1);
    }
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        ans=(ans%MOD*fast_pow(i->first,i->second,MOD)%MOD)%MOD;
    }
    return ans;
}
