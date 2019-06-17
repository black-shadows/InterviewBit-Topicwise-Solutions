int maxProfit(vector<int>& prices,int k) {
    if(k==0 || prices.size() == 0)
        return 0;
    int max_profit = 0;
    if(k >= prices.size()/2) {
        for(int i = 1;i < prices.size();i++) {
            max_profit += max(prices[i] - prices[i-1], 0);
        }
        return max_profit;
    }
    vector<vector<int>> dp(k+1, vector<int>(prices.size() + 1, 0));

    for(int i=1;i<=k;i++) {
        int maxDiff = -prices[0];
        for(int j = 2;j <= prices.size();j++) {
            dp[i][j] = max(dp[i][j-1], prices[j-1] + maxDiff);
            maxDiff = max(maxDiff, dp[i-1][j] - prices[j-1]);
        }
    }
    return dp[k][prices.size()];
}

int Solution::solve(vector<int> &A, int B) {
    return maxProfit(A,B);
}