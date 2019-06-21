int Solution::solve(vector<int> &A) {
        int n=A.size();
    if(n==0)
        return 0;
    unordered_map<int,int> mp;
    int sum=0,ans=0;
    mp[0]=-1;
    for(int i=0; i<A.size(); ++i){
        if(A[i]==0)
            --sum;
        else
            ++sum;
        if(mp.find(sum)==mp.end())
            mp[sum]=i;
        else
            ans=max(ans,i-mp[sum]);
    }
    return ans;
    
}