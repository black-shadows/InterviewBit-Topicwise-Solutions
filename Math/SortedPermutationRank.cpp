int factorial(int n)
{
    int i=0,ans=1;
    for(i=1;i<=n;i++)
    {
        ans=ans*i;
        ans=ans%1000003;
    }
    return ans;
}
int Solution::findRank(string A) {
    int i=0,j,c,ans=0;
    vector<int> H;
    while(A[i]!='\0')
    {
        j=i;
        c=0;
        while(A[j]!='\0')
        {
            if(A[i]>A[j])
                c++;
            j++;
        }
        H.push_back(c);
        i++;
    }
    c=0;
    i=H.size()-1;
    j=0;
    while(i>=0)
    {
        ans+=H[i]*factorial(j);
        ans=ans%1000003;
        j++;
        i--;
    }
    return ans+1;
}