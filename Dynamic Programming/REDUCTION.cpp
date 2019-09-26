int Solution::solve(vector<int> &A, int B)
{
    int N = (int)A.size();
    int K = B;
    if((N - 1) % (K - 1)) return -1;

    vector<int> sum(N + 1, 0);
    for(int i = 0; i < N; i++) sum[i + 1] = sum[i] + A[i];

    vector<vector<int> > dp(N + 1, vector<int>(N, 0));
    for(int l = K; l <= N; l++)
        for(int i = 0; i + l <= N; i++)
        {
            dp[l][i] = 10000;
            for(int k = 1; k < l; k += K - 1)
                dp[l][i] = min(dp[l][i], dp[k][i] + dp[l - k][i + k]);
            if((l - 1) % (K - 1) == 0) dp[l][i] += sum[i + l] - sum[i];
        }
    return dp[N][0];
}