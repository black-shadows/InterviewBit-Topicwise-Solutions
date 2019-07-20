int Solution::solve(vector <int> &A){
    int n=A.size();
    assert(n>=1&&n<=1000);
    for(auto &it:A)
        assert(it>=1&&it<=1000);
    int ans=0;
    int vis[1001]={0};
    vector<int> v;
    for(int i=0; i<n; ++i){
        v.push_back(A[i]);
        for(int j=1; j<=1000; ++j)
            if(vis[j])
                vis[__gcd(j,A[i])]=1;
        vis[A[i]]=1;
    }
    for(auto &it:vis)
        ans+=it;
    return ans;
}