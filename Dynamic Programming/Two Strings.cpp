const int N = 2e5 + 5;

int L[N], R[N];

int clean(int n){
for(int i=0; i<=n; ++i)
L[i]=R[i]=0;
}

int doit(vector<vector<int>> p, string &str,string &T){
int n = str.length();
int m = T.length();
clean(max(n,m));
int j = 0;
for (int i = 0; i <= m; ++i)
L[i] = n, R[i] = -1;
R[m] = n;
for (int i = 0; i < n; i++) {
if (j < m && str[i] == T[j]) {
L[j] = i;
j++;
continue;
}
}
j = m - 1;
for (int i = n - 1; i >= 0; --i) {
if (j >= 0 && str[i] == T[j]) {
R[j] = i;
j--;
}
}
for (int i = 0; i < m; ++i) {
p[T[i] - 'a'].push_back(i);
}
for (int i = 0; i < n; ++i) {
int k = str[i] - 'a';
if (p[k].size() == 0 || L[p[k][0]] > i) {
return 0;
}
int l = 0, r = p[k].size() - 1;
while (l < r) {
int mid = (l + r + 1) / 2;
if (L[p[k][mid]] <= i) l = mid;
else r = mid - 1;
}
if (R[p[k][l] + 1] <= i) {
return 0;
}
}
return 1;
}

int Solution::solve(string A, string B) 
{
    
vector<vector<int>> p(30);
return doit(p,A,B);
}