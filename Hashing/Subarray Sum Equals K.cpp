int Solution::solve(vector<int> &A, int B) {
    unordered_map<long long,int> mp;
    mp[0]=1;
    long long sum=0;
    int ans=0;
    for(auto &it:A){
        sum+=it;
        ans+=mp[sum-B];
        ++mp[sum];
    }
    return ans;
}