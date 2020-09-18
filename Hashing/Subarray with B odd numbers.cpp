int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), ans = 0, s = 0;
    vector<int> v(n+1, 0);
    
    for(int i=0; i<n; i++) {
        v[s]++;
        s += A[i]%2;
        if(s-B>=0)  ans += v[s-B];
    }
    
    return ans;
}