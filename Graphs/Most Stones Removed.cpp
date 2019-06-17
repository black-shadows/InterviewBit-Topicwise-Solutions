void init(vector<int> &parent,vector<int> &size){ for(int i=0; i<parent.size(); ++i){ parent[i]=i; size[i]=1; } }

int root(int x,vector<int> &parent){ while(x!=parent[x]){ parent[x]=parent[parent[x]]; x=parent[x]; } return x; }

void union_by_weight(int x,int y,vector<int> &parent,vector<int> &size)
{ 
    x=root(x,parent); 
    y=root(y,parent); 
    if(x==y) return; 
    if(size[x]>size[y]) swap(x,y); 
    size[y]+=size[x]; size[x]=0; 
    parent[x]=parent[y]; 
}

int solveit(vector<vector<int>>& stones) 
{ 
    int N=stones.size(); 
    if(N==0) return 0; 
    vector<int> parent(20000); 
    vector<int> size(20000); 
    init(parent,size); 
    for(auto &stone:stones)
    { 
        union_by_weight(stone[0],stone[1]+10000,parent,size); 
        
    } 
    unordered_set<int> s; 
    for(auto &stone:stones)
    { 
        s.insert(root(stone[0],parent)); 
    } 
    return N-s.size(); 
}

int Solution::solve(vector<vector<int> > &A) { return solveit(A); }