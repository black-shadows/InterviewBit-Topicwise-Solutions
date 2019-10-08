vector<pair<long long int,pair<long long int,long long int > > >edges;
const long long int mxn=1e5+5;
const long long int mod=1e9+7;
long long int par[mxn],size[mxn];
void initialize()
{
    for(int i=0;i<mxn;i++)
    {
        par[i]=i;
        size[i]=1;
    }
    edges.clear();
    
}
int find(long long int a)
{
    while(a!=par[a])
    {
        par[a]=par[par[a]];
        a=par[a];
    }
    return a;
}
void unionn(long long int a,long long int b)
{
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]<size[b])swap(a,b);
        par[b]=a;
        size[a]+=size[b];
    }
    
}
int Solution::solve(vector<vector<int> > &A) {
    long long int n=A.size(),i;
    initialize();
    for(i=0;i<n;i++)
    {
        edges.push_back(make_pair(A[i][2],make_pair(A[i][0],A[i][1])));
    }
    sort(edges.begin(),edges.end());
    long long int ans=0;
    for(i=0;i<n;i++)
    {
       // cout<<size[find(edges[i].second.first)]*size[find(edges[i].second.second)]<<endl;
        ans=(ans+edges[i].first*(size[find(edges[i].second.first)]*size[find(edges[i].second.second)]%mod)%mod)%mod;
        unionn(edges[i].second.first,edges[i].second.second);
    }
    return (int)ans%mod;
    
}