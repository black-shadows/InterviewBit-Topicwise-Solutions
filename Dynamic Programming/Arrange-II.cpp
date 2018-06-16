int product(string A){
    //cout<<A<<endl;
    int i,n=A.length();
    int w=0,b=0;
    for(i=0;i<n;i++){
        if(A[i]=='W')
            w++;
        else b++;
    }
    //printf("%d %d\n",w,b);
    return w*b;
}
long long answer(string A,int l,int k,int **a);
int memoize(string A,int l,int k,int **a){
    if(a[l][k]>=0)
        return a[l][k];
    a[l][k]=(int)answer(A,l,k,a);
    return a[l][k];
}
long long answer(string A,int l,int k,int **a){
    long long ans=INT_MAX;
    int r=A.length();
    if(k==0){
        return (long long)(product(A.substr(l,r-l)));
    }
    for(int i=l;i<r-k;i++){
        ans=min(ans,(long long)product(A.substr(l,i-l+1))+(long long)memoize(A,i+1,k-1,a));
        //printf("%d %d %lld\n",k,i,ans);
    }
    return ans;
}
int Solution::arrange(string A, int B) {
    if(B>A.length())
        return -1;
    int **a=new int*[A.length()];
    for(int i=0;i<A.length();i++)
        a[i]=new int[B];
    for(int i=0;i<A.length();i++)
        for(int j=0;j<B;j++)
            a[i][j]=-1;
    return (int)answer(A,0,B-1,a);
}