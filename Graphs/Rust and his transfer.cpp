typedef int ll;
const ll mod=1e9+15;
 
vector<ll> V[3001], dS(3001), dD(3001);
ll visit[3001], mat[3001][3001][2];
 
void dijkstra (ll s, vector<ll>& dist)
{
    set<pair<ll, ll>> S;
    memset(visit, 0, sizeof(visit));
    S.insert({0, s});
    while (!S.empty())
    {
        pair<ll, ll> p = *S.begin();
        S.erase(S.begin());
        ll u, v;
        u = p.first;
        v = p.second;
        if (visit[v])
            continue;
        visit[v] = 1;
        dist[v] = u;
        for (auto j : V[v])
        {
            ll d = mat[v][j][0];
            if (!visit[j] && (dist[v] + d)<dist[j])
            {
                dist[j] = dist[v] + d;
                S.insert({dist[j], j});
            }
        }
    }
    return;
}
int solveit(int A,vector<vector<int> > &B,int C,int D)
{
    ll  n, m, i, j, k, l, x, y, S;
        n=A;
        m=B.size();
        for (i=0; i<=3000; ++i)
            for (j=0; j<=3000; ++j)
                mat[i][j][0] = mat[i][j][1] = mod;
        for (i=0; i<m; ++i)
        {
            k=B[i][0];
            l=B[i][1];
            x=B[i][2];
            y=B[i][3];
            V[k].push_back(l);
            V[l].push_back(k);
            mat[k][l][0] = mat[l][k][0] = min(x, mat[k][l][0]);
            mat[k][l][1] = mat[l][k][1] = min(y, mat[k][l][1]);
        }
        S=C;
        for (i=0; i<=3000; ++i)
            dS[i] = dD[i] = mod;
       
        dijkstra(S, dS);
        dijkstra(D, dD);
       
        ll ans = dS[D];
        for (i=1; i<=3000; ++i)
        {
            for (auto j : V[i])
                ans = min(ans, dS[i]+dD[j]+mat[i][j][1]);
            V[i].clear();
        }
       
        if (ans!=mod)
            return ans;
        else
            return -1;
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
    return solveit(A,B,C,D);
}
