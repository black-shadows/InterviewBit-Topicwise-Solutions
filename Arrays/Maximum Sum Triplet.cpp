int Solution::solve(vector<int> &A) {
    int n=A.size();
    int dp[n]={0};
    dp[n-2]=A[n-1];
    for(int i=n-3;i>=0;i--)
    {
        dp[i]=max(dp[i+1],A[i+1]);
    }
    set<pair<int,int>> s;
    int ans=0;
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]<dp[i])
        {
            if(s.size()>0)
            {
                vector<pair<int,int>> v1,v2;
                auto it=s.end();
                it--;
                while(true)
                {
                   if(it->second>A[i])
                    {
                        ans=max(ans,it->first+A[i]);
                        if(A[i]+dp[i]>it->first)
                        {
                            v2.push_back({A[i]+dp[i],A[i]});
                        }
                    }
                    else if(A[i]+dp[i]>=it->first)
                    {
                        v1.push_back(*it);
                        v2.push_back({A[i]+dp[i],A[i]});
                    }
                    if(it==s.begin()) break;
                    it--;
                }
                for(auto x:v1) s.erase(x);
                for(auto x:v2) s.insert(x);
            }
            else
            {
                s.insert({A[i]+dp[i],A[i]});
            }
        }
    }
    if(ans) return ans;
    else return -1;
}