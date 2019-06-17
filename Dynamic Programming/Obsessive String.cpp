#define ll long long
const int md = 1000000007;
const int N = 100005;
int lcp[N];
bool found[N];
ll dp[N],predp[N],prepredp[N];

void clean(int n){
for(int i=0; i<=n; ++i){
dp[i]=0;
predp[i]=0;
prepredp[i]=0;
found[i]=0;
lcp[i]=0;
}
}

int doit(string &s,string &t){
int n = s.size();
int m = t.size();
if(m>n)
return 0;
clean(n);
int j = 0;
for(int i=1;i<m;i++){
while(j>0){
if(t[j] == t[i]){
lcp[i] = ++j;
break;
}
else
j = lcp[j-1];
}
if(j==0){
if(t[i] == t[j])
lcp[i] = ++j;
else
lcp[i] = 0;
}
}
j = 0;
for(int i=0;i<n;i++){
while(j>0){
if(s[i] == t[j]){
j++;
break;
}
else
j = lcp[j-1];
}
if(j==0){
if(s[i] == t[j])
j++;
}
if(j==m){
found[i-m+1] = 1;
}
}
j = -1;
ll ans = 0;
for(int i=m-1;i<n;i++)
{
if(found[i-m+1])
j = i-m+1;
if(j==-1)
continue;
dp[i] = (prepredp[j-1]+j+1)%md;
ans = (ans + dp[i])%md;
predp[i] = (predp[i-1]+dp[i])%md;
prepredp[i] = (prepredp[i-1]+predp[i])%md;
}
return (int)(ans);
}

int Solution::solve(string A, string B) {
return doit(A,B);
}