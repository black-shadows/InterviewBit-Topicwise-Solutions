int Solution::solve(vector<int> &a) {
    vector<int>cnt(200005,0);
    vector<int>r(200005,0);
    int last=0;
    int maxx=0;
    int ans=0;
    int most=0;
    
    for(int i = 0;i<a.size();i++){
        cnt[a[i]]++;
        r[a[i]] = i;
    }
    
    for (int i=0;i<a.size();i++)
    {
        most=max(most,cnt[a[i]]);
        maxx=max(maxx,r[a[i]]);
        if (maxx==i)
        {
            ans+=(i-last-most+1);
            most=0;
            last=i+1;
        }
    }return ans;
}
