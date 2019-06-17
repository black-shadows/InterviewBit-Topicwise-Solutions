const int N =100005;
int ctr=0;
int st[4*N], st2[4*N], ans[N];
map<int, int> m, rm;
map<int, int> idx;
pair<int, int> a[N];
vector<int> v;

void update(int node, int L, int R, int pos, int val){
if(L==R){
st[node]=val;
st2[node]=L;
return;
}
int M=(L+R)/2;
if(pos<=M)
update(node*2, L, M, pos, val);
else
update(node*2+1, M+1, R, pos, val);
st[node]=max(st[node*2], st[node*2+1]);
if(st[node]==st[node*2])
st2[node]=st2[node*2];
else
st2[node]=st2[node*2+1];
}

pair<int, int> query(int node, int L, int R, int i, int j){
if(j<L || i>R)
{
    
    pair<int, int> p = make_pair(-1000000000, 0);
    
    return p;
    
}
if(i<=L && R<=j)
return {st[node], st2[node]};
int M=(L+R)/2;
pair<int, int> left=query(node*2, L, M, i, j);
pair<int, int> right=query(node*2+1, M+1, R, i, j);
if(left.first>right.first)
return left;
return right;
}

void clean(int n){
v.clear();
idx.clear();
m.clear();
rm.clear();
for(int i=0; i<=4*n; ++i){
st2[i]=0;
st[i]=0;
if(i<=n)
ans[i]=0;
}
ctr=0;
}

vector<int> doit(vector<int> &x,vector<int> &h)
{ 
int n=x.size(); 
clean(n); 
for(int i=1; i<=n; ++i)
{ 
    a[i].first=x[i-1]; 
    a[i].second=h[i-1]; 
    idx[a[i].first]=i; 
    m[a[i].first]; 
    v.push_back(a[i].first); 
    
}
sort(v.begin(),v.end()); 
for(auto &it:m) 
it.second=++ctr; 
sort(a+1,a+n+1); 
vector<int> anss; 
for(int i=n; i>=1; --i)
{ 
    int cur=a[i].first; 
    int nxt=a[i].first+a[i].second; 
    auto it=lower_bound(v.begin(), v.end(), nxt); 
    it--; 
    int maxidx=m[*it]; 
    pair<int, int> p = query(1, 1, n, i, maxidx); 
    int curans; 
    if(p.first==0) 
    curans=1; 
    else 
    curans=p.first - i; 
    update(1, 1, n, i, i+curans); 
    ans[idx[a[i].first]]=curans; 
    
} 
for(int i=1;i<=n;i++) 
anss.push_back(ans[i]); 
return anss; 
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) 
{ 
    return doit(A,B); 
}