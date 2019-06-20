string Solution::solve(string A, string B) {
    int m = A.length();
    int n = B.length();
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(A[i] == B[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    if(i == m)
    {
        return "YES";
    }
    return "NO";
}