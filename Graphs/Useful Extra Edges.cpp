typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define se second
#define fi first
#define pb push_back
int n,m,kk,s,t,pp;

vector<vii> dist;
vector<vii> rdist;

const int INF = 1e9;

vi dists(100002,INF); //distance from source s to node
vi distt(100002,INF); //distance from node to target

void dijkstras(int source, vector<vii> &v,vector<int> &distance){
    priority_queue<ii,vii,greater<ii> > pq;
    pq.push(ii(0,source));
    distance[source]=0;
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
        int node = top.se;
        int d = top.fi;
        for(int i=0;i<v[node].size();++i){
            ii neighbor = v[node][i];
            if(distance[neighbor.fi]>d+neighbor.se){
                distance[neighbor.fi]=d+neighbor.se;
                pq.push(ii(distance[neighbor.fi],neighbor.fi));
            }
        }
    }
}
int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    dists = vi(100002,INF);
    distt = vi(100002, INF);
    n=A;
    dist = vector<vii> (n+1,vector<ii>());
    rdist = vector<vii> (n+1,vector<ii>());
    for(int i=0;i<B.size();i++)
    {
        dist[B[i][0]].push_back(ii(B[i][1],B[i][2]));
        rdist[B[i][1]].push_back(ii(B[i][0],B[i][2]));
    }
    dijkstras(C,dist,dists);
    dijkstras(D,rdist,distt);
    int ans = dists[D];
    for(int i=0;i<E.size();i++)
    {   int u=E[i][0];
        int v=E[i][1];
        int d=E[i][2];
        ans=min(ans,min(dists[u]+d+distt[v],dists[v]+d+distt[u]));
    }
    if(ans==INF)
        ans=-1;
    return ans;
}
