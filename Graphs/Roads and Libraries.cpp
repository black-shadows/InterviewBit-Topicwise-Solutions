int Rank[100001],dsu[100001];
int find(int x)
{
while(x!=dsu[x])
x=dsu[x];
return x;
}
void un_ion(int a,int b)
{
int x=find(a),y=find(b);
if(find(a)==find(b))
return;
if(Rank[x]<Rank[y])
dsu[x]=y;
else if(Rank[x]>Rank[y])
dsu[y]=x;
else
dsu[x]=y,Rank[y]++;
}
int solveit(int A,vector<vector<int>>B,int C,int D) 
{ 
    for(int i=0;i<=A;i++) 
    dsu[i]=i,Rank[i]=1; 
    for(auto i:B) 
    un_ion(i[0],i[1]);

int NOC=0;
for(int i=1;i<=A;i++)
    if(dsu[i]==i)
        NOC+=1;
return NOC*D + (A-NOC)*min(C,D); 
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D) 
{
    
    return solveit(A, B, C, D);
    
}
