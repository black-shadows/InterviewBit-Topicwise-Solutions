vector<int> anotherapproach(vector<int> &A,vector<int> &B){
    int n=A.size();
    int q=B.size();
    sort(A.begin(),A.end());
    map<int,int> mp;
    for(int i=0;i<n;){
        int j=i;
        for(;j<n-1;j++)
            if(A[j]<A[j+1]-1)
                break;
        for(int k=i;k<=j;k++)
            mp[A[k]]=A[j];
        i=j+1;
    }
    vector<int> ans;
    for(auto &x:B){
        if(mp[x]==0){
            if(mp[x+1]==0)
                ans.push_back(x+1);
            else
                ans.push_back(mp[x+1]+1);
        }
        else
            ans.push_back(mp[x]+1);
    }
    return ans;
}


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n=A.size();
    int m=B.size();
    vector<int> ans(m);
    pair<int,int> b[m];
    for(int i=0; i<m; ++i){
        b[i].first=B[i];
        b[i].second=i;
    }
    sort(A.begin(),A.end());
    sort(b,b+m);
    int x=b[0].first+1;
    int j=0,i=0;
    while(i<m){
        while(j<n&&x>A[j])
            ++j;
        if(j<n&&x==A[j]){
            ++x;
            continue;
        }
        while(i<m&&x>b[i].first){
            ans[b[i].second]=x;
            ++i;
        }
        if(i<m)
            x=b[i].first+1;
    }
    return ans;
}