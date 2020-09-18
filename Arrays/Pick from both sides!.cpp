int Solution::solve(vector<int> &a, int k) {
    int n=a.size();
    vector<int> prefix(n,0);
    for(int i=0;i<n;i++)
    prefix[i]=a[i]+(i==0?0:prefix[i-1]);
    int l=k-1,r=n,ans=INT_MIN;
    while(l>=-1){
        ans=max(ans,(l>=0?prefix[l]:0)+prefix[n-1]-prefix[r-1]);
        l--,r--;
    }
    return ans;
}
