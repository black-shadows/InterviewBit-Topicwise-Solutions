int Solution::solve(int n) {
    long dp[100];
    for(int i = 0; i < 100; i++)    dp[i] = 1000;
    dp[0] = 0;
    for(int i = 1; i < 100; i++)    dp[i] = min(dp[i-1] + 1, dp[i]);
    for(int i = 10; i < 100; i++)    dp[i] = min(dp[i-10] + 1, dp[i]);
    for(int i = 25; i < 100; i++)    dp[i] = min(dp[i-25] + 1, dp[i]);
    long ans = 0;
    while(n > 0) {
        ans += dp[(int)(n % 100)];
        n /= 100;
    }
    return ans;
}
