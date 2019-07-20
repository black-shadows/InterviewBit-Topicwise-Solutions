#define mxn 100005
#define mxnn 200005
#define mod (ll)10000000
#define ll long long
int a[mxn];
unordered_map <int, int> m;
string Solution::solve(string A,int B, int C)
{
    m.clear();
    int n =A.length(),total = n;
    string ans = A;
    for(int i=0;i<n;i++)
    {
        a[i] = i;
    }
    for(int i=1;i<=1000000;i++)
    {
        swap(a[i%n],a[(i+C)%n]);
    }
    for(int i=0;i<n;i++)
    {
        m[i] = a[i];
    }
    int p = B/1000000;
    //B = B - p*1000000;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<n;j++){
        ans[j] = A[m[j]];
        }
        A = ans;
    }

    for(int i = p*1000000 + 1;i<=B ;i++)
    {
        swap(A[i%n],A[(i + C)%n]);
    }
    return A;
}