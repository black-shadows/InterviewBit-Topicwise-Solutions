struct Box{
    int height;
    int width;
    int depth;
    Box(){
        height=0;
        width=0;
        depth=0;
    }
    Box(int x,int y,int z){
        height=x;
        depth=y;
        width=z;
    }
};

bool compare(const Box &A,const Box &B){
    long long basearea1=1LL*A.width*A.depth;
    long long basearea2=1LL*B.width*B.depth;
    return basearea1>basearea2;
}


int maxheightstack(vector<vector<int>> &A){
    int n=A.size();
    vector<Box> rot;
    for(int i=0; i<n; ++i){
        Box c1=Box(A[i][0],max(A[i][1],A[i][2]),min(A[i][1],A[i][2]));
        Box c2=Box(A[i][1],max(A[i][0],A[i][2]),min(A[i][0],A[i][2]));
        Box c3=Box(A[i][2],max(A[i][1],A[i][0]),min(A[i][1],A[i][0]));
        rot.push_back(c1);
        rot.push_back(c2);
        rot.push_back(c3);
    }
    sort(rot.begin(),rot.end(),compare);
    int dp[n+n+n];
    assert(rot.size()==n+n+n);
    for(int i=0; i<n+n+n; ++i)
        dp[i]=rot[i].height;
    for(int i=1; i<n+n+n; ++i){
        for(int j=0; j<i; ++j){
            if(rot[i].width<rot[j].width && rot[i].depth<rot[j].depth && dp[i]<dp[j]+rot[i].height)
                dp[i]=rot[i].height+dp[j];
        }
    }
    int mx=0;
    for(int i=0; i<n+n+n; ++i)
        mx=max(mx,dp[i]);
    return mx;
}

int Solution::solve(vector<vector<int> > &A) {
    return maxheightstack(A);
}