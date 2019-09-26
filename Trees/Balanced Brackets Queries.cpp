#define pb push_back
struct Node{
    int val=0,o=0,c=0;
};
void build(string &str,Node* tree,int nd, int s, int e){
    if (s==e) {tree[nd].val=0;
        if (str[s]=='(') {tree[nd].o=1;}
        else {tree[nd].c=1;}
        return;
    }
    int m = (s+e)/2;
    build(str,tree,2*nd,s,m);
    build(str,tree,(2*nd)+1,m+1,e);
    int t = min(tree[2*nd].o, tree[(2*nd)+1].c);
    tree[nd].val = tree[2*nd].val+tree[(2*nd)+1].val+t;
    tree[nd].o = tree[2*nd].o+tree[(2*nd)+1].o-t;
    tree[nd].c = tree[2*nd].c+tree[(2*nd)+1].c-t;
    return;
}
Node que(Node* tree, int nd, int s, int e, int l, int r){
    if (s==l and e==r) {return tree[nd];}
    int m = (s+e)/2;
    Node p1,p2,ans;
    if (r<=m) {return que(tree,2*nd,s,m,l,r);}
    if (l>=m+1) {return que(tree,(2*nd)+1,m+1,e,l,r);}
    p1 = que(tree,2*nd,s,m,l,m);
    p2 = que(tree,(2*nd)+1,m+1,e,m+1,r);
    int t = min(p1.o,p2.c);
    ans.val = p1.val+p2.val+t;
    ans.o = p1.o+p2.o-t;
    ans.c = p1.c+p2.c-t;
    return ans;
}
vector<int> Solution::solve(string A, vector<vector<int> > &B) {
    int n = A.size();
    vector<int> ans;
    Node tree[4*n+5];
    for (int i=n;i>0;i--){
        A[i] = A[i-1];
    }   
    build(A,tree,1,1,n);
    for (int i=0;i<B.size();i++){
        ans.pb(2*que(tree,1,1,n,B[i][0],B[i][1]).val);
    }
    return ans;
}
