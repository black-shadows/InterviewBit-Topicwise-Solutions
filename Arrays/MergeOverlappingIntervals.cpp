bool comp(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
 

vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> ans;
    int i=1,f=0;
    sort(A.begin(),A.end(),comp);
    Interval s;
    s.start=A[0].start;
    s.end=A[0].end;
    while(i<A.size())
    {
        if(A[i].start>s.end)
        {
            ans.push_back(s);
            s.start=A[i].start;
            s.end=A[i].end;
        }
        else if(A[i].end>s.end)
            s.end=A[i].end;
        i++;
        
    }
    ans.push_back(s);
    return ans;
}