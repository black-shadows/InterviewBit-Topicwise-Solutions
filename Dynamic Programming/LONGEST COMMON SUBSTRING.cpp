int L[1001][10001];

int Solution::solve(string A, string B) {
    
    int maxlen = 0;
    for (int i = 1; i <= A.length(); i++)
    {
        for (int j = 1; j <= B.length(); j++)
        {
            if(A[i-1] == B[j-1]){
                L[i][j] = L[i-1][j-1]+1;
                maxlen = max(maxlen, L[i][j]);
            }
            else
                L[i][j] = 0;
        }
    }

    return maxlen;
}