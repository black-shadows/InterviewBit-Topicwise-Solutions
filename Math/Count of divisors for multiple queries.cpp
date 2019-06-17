vector<int> Solution::solve(vector<int> &A) {
    int mx = *max_element(A.begin(), A.end()) + 2;
    vector<int> d(mx);
    for (int i = 0; i < mx; ++i)d[i]=i;
    for (int i = 2; i*i < mx; ++i)if(d[i]==i) {
        for (int j = i*i; j < mx; j+=i)d[j]=i;
    }
    auto res = A;
    
    for (int i = 0; i < A.size(); ++i) {
        int r = 1, x = A[i];
        while(x > 1) {
            int p = d[x], c = 0;
            while(x%p==0)++c,x/=p;
            r *= c + 1;
        }
        res[i]=r;
    }
    
    return res;
}
