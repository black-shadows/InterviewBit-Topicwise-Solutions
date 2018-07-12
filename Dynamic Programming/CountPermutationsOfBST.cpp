const int MOD = 1e9 + 7;

int dp[51][51];
int nCr[51][51];

inline int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

inline int mul(int a, int b) {
    return a * 1LL * b % MOD;
}

int Solution::cntPermBST(int A, int B) {
    memset(dp, 0, sizeof dp);
    memset(nCr, 0, sizeof nCr);
    nCr[0][0] = dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i <= A; ++i) {
        nCr[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            nCr[i][j] = add(nCr[i-1][j-1], nCr[i-1][j]);
        }
    }
    for (int i = 2; i <= A; ++i) {
        for (int j = 1; j <= i; ++j) {
            int ltht = max(j-1, 1), rtht = max(i-j, 1);
            int sdp = 0, p = nCr[i-1][j-1];
            for (int k = 0; k < ltht; ++k) {
                sdp = add(sdp, dp[i-j][k]);
                int L = dp[j-1][k];
                dp[i][k+1] = add(dp[i][k+1], mul(mul(L, sdp), p));
            }
            sdp = 0;
            for (int k = 0; k < rtht; ++k) {
                int R = dp[i-j][k];
                dp[i][k+1] = add(dp[i][k+1], mul(mul(R, sdp), p));
                sdp = add(sdp, dp[j-1][k]);
            }
        }
    }
    return dp[A][B];
}