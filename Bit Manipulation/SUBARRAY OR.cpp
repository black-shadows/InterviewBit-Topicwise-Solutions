int mod = 1000000007;

int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    vector<int> p(n);
    vector<vector<int>> v (32,p);
    int index=n;
    for(int i=0; i<32; i++) {
        index=n;
        for(int j=n-1; j>=0; j--) {
            int t = A[j]&(1<<(i));
            if(t!=0) {
                index=j;
            }
            v[i][j]=index;
        }
    }
    
    long long sum=0;
    for(int i=0; i<32; i++) {
        long long s=0;
        for(int j=0; j<n; j++) {
            s+=(n-v[i][j]);
        }
        s = s*(1<<i);
        sum = (sum+s)%mod;
    }
    
    return sum%mod;
}
