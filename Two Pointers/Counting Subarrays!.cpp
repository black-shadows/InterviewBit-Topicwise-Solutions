int Solution::solve(vector<int> &A, int B) {
    int i=0,j=0,count=0;
    int sum=0;
    while(j<A.size())
    {
        if(sum+A[j]<B)
        {
            count+=(j-i+1);
            sum+=A[j];
            j++;
        }
        else
        {
            sum-=A[i];
            i++;
        }
    }
    return count;
}