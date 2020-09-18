int num(char c)
{
    return c - '0';
}
void reverse(string& A,int i,int j)
{
    while(i<j)
    {
        swap(A[i],A[j]);
        i++;
        j--;
    }
}
string Solution::solve(string A) {

    int i;
    int n = A.size();
    for(i=n-2;i>=0;i--)
    {
        if(num(A[i])<num(A[i+1]))
            break;
    }
    
    // already the maximum number
    if(i==-1)
    return "-1";
    
    // replace this number with greatest right most number
    int j = n-1;
    for(;j>i;j--)
    {
        if(num(A[j])>num(A[i]))
            break;
    }
    // swap with this number
    swap(A[j],A[i]);
    
    // remaining numbers from A[i+1] to A[j] // all are greater than 3 and sholud ber reversed
    reverse(A,i+1,n-1);
    return A;
}