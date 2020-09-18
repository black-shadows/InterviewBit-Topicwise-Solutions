int findpar(int x,vector<int>&par){
    while(par[x]!=-1)
    x=par[x];
    return x;
}
int Solution::solve(int A, vector<vector<int> > &B) {
vector<int> par(A+1,-1);
 for(int i=0;i<B.size();i++){
     int x=findpar(B[i][0],par);
     int y=findpar(B[i][1],par);
     if(x==y)return 1;
     par[x]=y;
 }
    return 0;
}
