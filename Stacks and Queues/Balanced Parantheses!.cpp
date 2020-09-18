int Solution::solve(string str)
{
    int n=str.length(),i;
    if(n==1)
    return 0;
    stack<char>s;
    for(i=0;i<n;i++)
    {
        if(str[i]=='(')
        s.push(str[i]);
        else
        {
            if(s.empty())
            return 0;
            else if(s.top()!='(')
            return 0;
            else
            s.pop();
        }
    }
    if(s.empty())
    return 1;
    return 0;
}