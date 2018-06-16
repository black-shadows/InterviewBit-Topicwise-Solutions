bool isPalindrome(string s)
{
    for(int i=0;i<s.length()/2;i++)
    {
        if(s[i] != s[s.length()-i-1])
        {
            return 0;
        }
    }
    return 1;
}

void PartitionString(string &S,vector<vector<string> > &toreturn,vector<string> &curr,int beg)
{
    if(beg == S.size())
    {
        toreturn.push_back(curr);
        return;
    }
    for(int i=1;i<=(S.length()-beg);i++)
    {
        if(isPalindrome(S.substr(beg,i)))
        {
            curr.push_back(S.substr(beg,i));
            PartitionString(S,toreturn,curr,beg+i);
            curr.pop_back();
        }
    }
    return;
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string> > toreturn;
    vector<string> temp;
    PartitionString(A,toreturn,temp,0);
    return toreturn;
}
