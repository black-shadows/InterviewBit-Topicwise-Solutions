int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int res = A[0]^A[1];
    for(int i=1 ; i<A.size() ; ++i)
        res = min(res, A[i]^A[i-1]);
    return res;
    
}