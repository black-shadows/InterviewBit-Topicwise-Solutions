typedef unsigned long long ull;
typedef long long int ll;
typedef vector<long long int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int Solution::solve(vector<int> &a, int B) 
{

    ll n,c;
    n = a.size();
    c = B;
    sort(a.begin(),a.end());
    ll i=1,j=1000000001,ans=0,l=0;
    while(i<=j)
    {
        ll mid=((j+i)/2);
        int fi=a[0],temp=1;
        for(int k=1;k<n;k++)
        {
            if(a[k]-fi>=mid)
                temp++,fi=a[k];
        }
        if(temp<c)
            j=mid-1;
        else
        {
            ans=mid;
            i=mid+1;
        }
    }
    return ans;
}
