int palindrome(string s)
{
    
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        return 0;
    }
    return 1;
}
int Solution::solve(string a) {
    int l=a.size();
    if(palindrome(a)==1)
    return 0;
    int c=0;
    while(l--)
    {
        string s=a.substr(++c);
        if(palindrome(s)==1)
        {
            break;
        }
    }
    return c;
}