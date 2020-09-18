bool allNine(string s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!='9')
            return false;
    }
    return true;
}

string Solution::solve(string s) {
    string str="";
    if(allNine(s))
    {
        str.push_back('1');
        for(int i=0; i<s.size()-1; i++)
            str.push_back('0');
        str.push_back('1');
            return str;
    }
    else
    {
        int n=s.size();
        int mid=n/2;
        int i=mid-1;
        int j=(n%2==0)?mid:mid+1;
        bool leftSmaller=false;
        while(i>=0 && s[i]==s[j])
        {
            i--;
            j++;
        }
        if(i<0 || s[i]-'0'<s[j]-'0')
        {
            leftSmaller=true;
        }
        while(i>=0)
        {
            s[j]=s[i];
            i--;
            j++;
        }
        if(leftSmaller==true)
        {
            i=mid-1;
            int carry=1;
            if(n%2==1)
            {
                int x=(s[mid]-'0')+carry;
                carry=x/10;
                x=x%10;
                s[mid]=x+'0';
                j=mid+1;
            }
            else
                j=mid;
            while(i>=0)
            {
                int x=(s[i]-'0')+carry;
                carry=x/10;
                x=x%10;
                s[i]=x+'0';
                s[j++]=s[i--];
            }
        }
        return s;
    }
}
