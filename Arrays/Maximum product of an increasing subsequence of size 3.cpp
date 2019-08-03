const int mod = 1000000007;


int solveit(vector<int> &a){
    int n=a.size();
    long long ans=-1;
    long long smaller[n];
    set<long long> s;
    memset(smaller,-1,sizeof smaller);
    set<long long>::iterator it;

    for(int i=0; i<n; ++i){
        s.insert(a[i]);
        it=s.lower_bound(a[i]);
        if(it!=s.begin()){
            --it;
            smaller[i]=*it;
        }
    }
    long long suffixmax=a[n-1];
    for(int i=n-2; i>0; --i){
        if(a[i]>suffixmax)
            suffixmax=a[i];
        else if(smaller[i]!=-1){
            long long temp=1LL*smaller[i]*a[i]*suffixmax;
            if(ans<temp)
                ans=temp;
        }
    }
    if(ans!=-1)
        ans%=mod;
    return (int)(ans);
}


int Solution::solve(vector<int> &A) {
    return solveit(A);
}
