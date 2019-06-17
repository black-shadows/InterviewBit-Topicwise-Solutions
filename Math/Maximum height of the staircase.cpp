int Solution::solve(int n) 
{
    
    int ans=0;
    int p=1;
    while(n>0)
    {
        if(n>=p)
        {
            ans++;
            n-=p;
        }
        else
        break;
        p++;
    }
    return ans;
}
