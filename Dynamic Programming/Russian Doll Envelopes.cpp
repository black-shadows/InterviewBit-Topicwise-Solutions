int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), [](const vector<int> & p1, const vector<int> & p2){
        return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
    });
    vector<int>dp;
    for(auto x: A){
        int pos = lower_bound(dp.begin(), dp.end(), x[1]) - dp.begin();
        if(pos == dp.size()) dp.push_back(x[1]);
        else dp[pos] = x[1];
    }
    return dp.size();
}