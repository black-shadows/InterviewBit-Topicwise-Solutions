bool palindrome(string ::iterator itr,string :: iterator itr1)
{
    while(itr<itr1)
    {
        if(*itr!=*itr1)
        {
            return false;
        }
        itr++;
        itr1--;
    }
    return true ;
}
int Solution::solve(string str) {
    int n=str.size(),l=0,r=n-1;
    while(l<=r)
    {
        if(str[l]==str[r])
        {
            l++;
            r--;
        }
        else
        {
            if(palindrome(str.begin()+l+1,str.begin()+r) || palindrome(str.begin()+l,str.begin()+r-1) )
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}