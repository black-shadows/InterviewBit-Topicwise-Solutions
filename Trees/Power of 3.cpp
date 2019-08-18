#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 99999999
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mp make_pair
#define mxn 100005
#define mxnn 200005
#define mod (ll)1000000007
#define ll long long
int BIT[2][mxn];
void update(int loc,int index,int val)
{
    for(int i = index;i<mxn;i+= (i & (-i)))
    {
        BIT[loc][i]+=val;
    }
}
int query(int loc,int index)
{
    int sum = 0;
    for(;index>0; index-=(index & (-index)))
    {
        sum += BIT[loc][index];
    }
    return sum;
}
vector<int> Solution::solve(string A, vector <vector <int> > &B)
{
    memset(BIT, 0, sizeof(BIT));
    vector <int> ans;
    int n = A.size();
    int q = B.size();
   // cout<<n<<" "<<q<<endl;
    for(int i=0;i<n;i++)
    {
        if(A[i] == '1')
        {
            update( (i+1)%2, (i+2)/2, 1 );
        }
    }
    for(int i=0;i<q;i++)
    {
        int type = B[i][0];
        if(type==1)
        {
                int index = B[i][1];
                if(A[index-1] == '1')
                {
                    ans.push_back(-1);
                    continue;
                }
                else
                {
                    ans.push_back(-1);
                    A[index-1] = '1';
                    update(index%2, (index+1)/2, 1);
                }

        }
        else
        {
            int l = B[i][1];
            int r = B[i][2];
            if(r%2==0)
            {
                ans.pb((query(0,(r+1)/2) - query(0,(l-1)/2) + (query(1,(r+1)/2) - query(1,(l)/2))*2)%3);
            }
            else
            {
                ans.pb(((query(0,(r)/2) - query(0,(l-1)/2))*2 + (query(1,(r+1)/2) - query(1,(l)/2)))%3);
            }
        }
    }
    return ans;
}