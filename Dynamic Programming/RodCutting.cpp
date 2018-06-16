vector<int> constructParent(int l,int r,vector<vector<int>> &p,vector<int> &B){
    stack<int> ls;
    stack<int> rs;
    vector<int> v ;
    ls.push(l);rs.push(r);
    while(!ls.empty()){
        l=ls.top();
        r=rs.top();
        ls.pop();rs.pop();
        if(l<r){
            v.push_back(B[p[l][r]]);
            ls.push(p[l][r]+1);
            rs.push(r);
            ls.push(l);
            rs.push(p[l][r]);
        }
    }
    return v;
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
     vector<int> v;
    int i,j,k,p;
    long long t;
    int n=B.size()+1;
    if(n==1)
        return v;
    vector<vector<int>> pi;
    long long M[n][n];
   long long l[n][n];
    
    for(i=0;i<n;i++){
        vector<int> row(n,-1);
        pi.push_back(row);
    }
   
   memset(l,0,sizeof(l));
   memset(M,0,sizeof(M));
    sort(B.begin(),B.end());
    
   for(i=0;i<n;i++){
        for(j=0;j<n;j++)
           pi[i][j]=-1;
    }
    l[0][0]=B[0];
    for(i=1;i<n-1;i++)
        l[i][i]=B[i]-B[i-1];
    l[n-1][n-1]=A-B[n-2];
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            l[i][j]=l[i][j-1]+l[j][j];
    for(k=1;k<n;k++){
        i=0;j=i+k;
        while(j<n){
            t=LONG_MAX;
            for(p=i;p<=j-1;p++){
                if(t>M[i][p]+M[p+1][j]){
                    t=M[i][p]+M[p+1][j];
                    pi[i][j]=p;
                }
            }
            M[i][j]=l[i][j]+t;
            i+=1;
            j+=1;
        }
    }
    v=constructParent(0,n-1,pi,B);
    return v;
}