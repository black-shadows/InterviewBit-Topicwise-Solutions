int Solution::solve(vector<int> &A, int B) {
    int min=INT_MAX;long sum=A[0];
    int start=0;
    if(sum>=B)
    {
    min=1;
    return 1;
    }
    for(int i=1;i<A.size();i++)
    {
        sum+=A[i];
        //cout<<sum<<endl;
        while(sum>=B && start <=i)
        {   if((i-start)+1<min)
             min=(i-start)+1;
            sum-=A[start];
            //cout<<sum<<endl;
            start++;
            
        }
        
    }
    if(min==INT_MAX)
    return -1;
    else
    return min;
}