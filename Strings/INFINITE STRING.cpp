int bc(int n, int k)
{
    return n * (n-1) / 2;
}
int Solution::solve(string A) {
    const int n =  A.length();
    int d = 0, add = 1;
    for (int i = 1; i < n; ++i) {
        if (A[i] == A[i-1])
            d += add, add++;
        else
            add = 1;
    }
    return ((long)n * (n-1) / 2 - d) % 10000000;
}
