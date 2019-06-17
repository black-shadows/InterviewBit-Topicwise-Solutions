int Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int,int>ma1,ma2;
    
    for(int i=0;i<A.size();i++)
    {
        ma1[A[i]]++;
    }
    for(int i=0;i<B.size();i++)
    {
        ma2[B[i]]++;
    }
    long long int cnt=0;
    for(int i=0;i<A.size();i++)
    {
        cnt+= 1LL*(ma1[A[i]]-1)*(ma2[B[i]]-1);
        cnt%=1000000007;
    }
    return cnt;
}