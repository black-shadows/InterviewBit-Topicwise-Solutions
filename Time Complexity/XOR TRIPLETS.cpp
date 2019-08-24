int Solution::solve(vector <int> &A)
{
int n = A.size();
long long xorval = 0;
map<long long, pair<long long, long long>> m;
pair<long long, long long> p;
p.first = -1;
p.second = 1;
m[xorval] = p;
long long ans = 0;
for (int i = 0; i < n; i++) {
xorval ^= A[i];
if (m.find(xorval) == m.end()) {
pair<long long, long long> p;
       p.first = i;
       p.second = 1;
       m[xorval] = p;
} else {
pair<long long, long long> p = m[xorval];
long long x = p.first;
long long y = p.second;
ans += i * y - x - y;
p.first += i;
p.second++;
m[xorval] = p;
}
}
return ans;
}
