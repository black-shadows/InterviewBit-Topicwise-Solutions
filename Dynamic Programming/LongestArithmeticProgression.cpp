int Solution::solve(const vector<int> &a) {
    int n=a.size();
    if(n<=2) return n;
    int A[n];
    for(int i=0;i<n;i++)
     A[i]=a[i];
    sort(A,A+n);
    int l[n];
    l[0]=1;
    for(int i=1;i<n;i++){
        l[i]=2;
    }
    int ans=2;
    for(int j=n-2;j>0;j--){
        int i=j-1,k=j+1;
      while(i>=0&&k<n){
        if(A[i]+A[k]==2*A[j]){
         l[j]=max(l[j],l[k]+1);
         ans=max(ans,l[j]);
         i--;k++;
        }
        else if(A[i]+A[k]<2*A[j])
         k++;
        else i--;
      }
    }
    return ans;
}