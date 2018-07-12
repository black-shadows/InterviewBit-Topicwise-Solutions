int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    if (!n) return 0;
    
    int i;
    int rv = A[n - 1];
    
    for (i = n - 2; (i > 0)&&(A[i] >= rv); --i) {
        rv = A[i];
    }
    int end = i + 1; // exlusive

    for (;(i > 0)&&(A[i] <= rv); --i) {
        rv = A[i];
    }
    int start = i + 1;

    if (i <= 0) return 0;
    
    //printf("%i %i --- ", start, end);
    long max = 0;
    for (int j = start; j < end; ) {
        int mid = j;
    
        for (; (i>=0)&&(A[i]<=A[mid]); --i);
        if (i < 0) break;
        
        for (; (j <= end)&&(A[j] == A[mid]); ++j);
        if (j > end) break;
        
        int left = i;
        int right = j;
    
        long res = (long)left*(long)right;
        if (res > max) max = res;
    }
    
    return max%1000000007;
}
