const int N = 1e5 + 10;
int f[N];

vector<int> Solution::solve(vector<int> &A, int B) {
    
    vector< int > res;
    int j = 0, cnt = 0, n = A.size();
    
    assert(1 <= n);
    assert(n <= 100000);
    assert(1 <= B);
    assert(B <= n);
    
    res.resize(n);
    memset(f, 0, sizeof(f));
    
    for(int i = 0; i < n; i++) {
        assert(A[i] >= 1);
        assert(A[i] <= 100000);
        while( j < n && cnt + !f[A[j]] <= B ) {
            cnt += !f[A[j]];
            f[A[j]]++;
            j++;
        }

        res[j-i-1]++;
        
        f[A[i]]--;
        if( f[A[i]] == 0 ) cnt--;
    }



    for( int i = n-2; i >= 0; i-- )
        res[i] += res[i+1];

    return res;
    
}