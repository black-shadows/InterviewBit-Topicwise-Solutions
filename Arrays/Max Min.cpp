int Solution::solve(vector<int> &A) 
{
    int n=A.size();
    int maxm=A[0],minm=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]>maxm) maxm=A[i];
        else if(A[i]<minm) minm=A[i];
    }
    return maxm+minm;
}