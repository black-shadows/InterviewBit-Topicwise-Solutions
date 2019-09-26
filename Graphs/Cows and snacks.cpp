int dsu[100001];
int find(int x)
{
    while(x!=dsu[x])
    {
        dsu[x]=dsu[dsu[x]];
        x=dsu[x];
    }
    return x;
}

int solveit(int A,vector<vector<int> > &B)
{
    int ans=0;
    for(int i=0;i<=A;i++)
        dsu[i]=i;
    for(auto i:B)
        if(find(i[0])==find(i[1]))
            ans++;
        else
            dsu[find(i[0])]=find(i[1]);
    return ans;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    return solveit(A,B);
}