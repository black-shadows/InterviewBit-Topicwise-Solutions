int dp[105][105];
int rec(int i,int j,vector<int> &A){
        if(j-i<=1)
            return 0;
        auto &ans=dp[i][j];
        if(ans!=-1)
            return ans;
        ans=0;
        for(int k=i+1; k<=j-1; ++k)
            ans=max(ans,rec(i,k,A)+rec(k,j,A)+A[i]*A[k]*A[j]);
        return ans;
}
int maxCoins(vector<int>& A) {
    A.insert(A.begin(), 1);
    A.push_back(1);
    int n=A.size();
    for(int i=0;i<=n; ++i)
        for(int j=0; j<=n; ++j)
            dp[i][j]=-1;
    int ans=rec(0,n-1,A);
    assert(ans<=INT_MAX);
    return ans;
}

int Solution::solve(vector<int> &A) {
    return maxCoins(A);
}