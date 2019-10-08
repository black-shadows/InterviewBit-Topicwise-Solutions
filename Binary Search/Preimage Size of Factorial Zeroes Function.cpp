long long numberofzeroes(long long x)
{
    long long ans=0,five=5;
    while(five<=x)
    {
        ans+=x/five;
        five*=5;
    }
    return ans;
}
int solveit(int K) {
    long long lostart=0,histart=5e9,loend=0,hiend=5e9,start=-1,end,mid;
    while(lostart<=histart)
    {
        mid=(lostart+histart)/2;
        if(numberofzeroes(mid)<K)
        {
            lostart=mid+1;
        }
        else if(numberofzeroes(mid)>K)
        {
            histart=mid-1;
        }
        else
        {
            start=mid;
            histart=mid-1;
        }
    }
    if(start==-1)
        return 0;
    while(loend<=hiend)
    {
        mid=(loend+hiend)/2;
        if(numberofzeroes(mid)<K)
        {
            loend=mid+1;
        }
        else if(numberofzeroes(mid)>K)
        {
            hiend=mid-1;
        }
        else
        {
            end=mid;
            loend=mid+1;
        }
    }
    return end-start+1;
}
int Solution::solve(int A) {
    return solveit(A);
}
