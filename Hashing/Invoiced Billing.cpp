int Solution::countMismatchedPayments(vector<string> &A, vector<int> &B, vector<string> &C, vector<int> &D) {
    unordered_map<string,int> mp;
    int cnt=0;
    for (int i=0;i<A.size();i++){
        mp[A[i]] = B[i];
    }
    for (int i=0;i<C.size();i++){
        if (mp[C[i]]!=D[i]) {cnt++;}
    }
    return cnt;
}
