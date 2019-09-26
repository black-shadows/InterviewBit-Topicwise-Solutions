int Solution::solve(vector <int> &A, vector <int> &B)
{
    int n = A.size();
    int m = B.size();
    int ptr1 = 0,ptr2 = 0;
    int ans = 0,last = 0;
    while(ptr1<n && ptr2<m)
    {
        if(A[ptr1] < B[ptr2])
        {
            if(last == 0 || last == 1)
            {
                last = 1;
            }
            else
            {
                last = 1;
                ans++;
            }
            ptr1++;
        }
        else
        {
            if(last == 0 || last == 2)
            {
                last = 2;
            }
            else
            {
                ans++;
                last = 2;
            }
            ptr2++;
        }
    }
    if(n!=0 && m!=0)
    {
        ans++;
    }
    return ans;
}