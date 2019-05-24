vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    pair<int,int>a[10004];
    int n=A.size();
    int m=B.size();
    for(int i=0;i<n;i++)
    {
        a[i].first=A[i];
        a[i].second=-1;
    }
    for(int i=0;i<m;i++){
        a[i+n].first=B[i];
        a[i+n].second=1;
        
    }
    sort(a,a+n+m);
    int x=n*3,mx,my;
    int y=m*3;
    mx=x;
    my=y;
    for(int i=0;i<m+n;i++){
        if(a[i].second==1)
        y--;
        else
        x--;
        if(x-y>mx-my)
        {
            mx=x;
            my=y;
        }
    }
    vector<int>ans;
    ans.push_back(mx);
    ans.push_back(my);
    return ans;
}