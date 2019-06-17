int maxProfit(vector<int>& a) {
    int n=a.size();
    if(n==0)
        return 0;
    vector<int> buy(n, 0), sell(n, 0);
    buy[0]=-a[0];
    sell[0] = 0;
    for(int i=1; i<n; i++) {
        buy[i]=max(buy[i-1],(i-2>=0 ? sell[i-2]:0)-a[i]);
        sell[i]=max(sell[i-1],buy[i-1]+a[i]);
        }
    return max(buy[n-1], sell[n-1]);
}

int Solution::solve(vector<int> &A) {
    return maxProfit(A);
}