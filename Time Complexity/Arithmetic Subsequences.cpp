int Solution::solve(vector<int> &A) 
{
    if(A.empty()) return 0;
    vector<unordered_map<int,int>> dp(A.size());//[index, [difference, count]]
    
    int res = 0;
    for(int i = 0; i < A.size(); ++i){
        for(int j = 0; j < i; ++j){
            if((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;// do not ignore this step, it will help you save time & space to pass OJ.
            int dif = A[i] - A[j];
            dp[i][dif] += 1;
            if(dp[j].find(dif) != dp[j].end()){
                dp[i][dif] += dp[j][dif];
                res += dp[j][dif];
            }
        }
    }
    return res;
}
