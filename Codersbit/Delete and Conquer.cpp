int Solution::deleteandconquer(vector<int> &a) {
    vector<int> c(1000001,0);
    for(int i=0;i<a.size();i++)
    {
        c[a[i]]++;
    }
    int mx=0,n=a.size();
    for(int i=0;i<1000001;i++)
    {
        mx = max(mx,c[i]);
    }
    return n-mx;
}