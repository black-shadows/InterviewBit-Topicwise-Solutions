int Solution::perfectPeak(vector<int> &A) {
    int n=A.size();
    int i=1,l=A[0];
    if(n<3)
        return 0;
    while(i<n-1)
    {
        if(A[i]>l)
        {
            l=A[i];
            int j=i+1;
            while(j<n)
            {
                if(A[j]<l)
                {
                    i=j;
                    break;
                }
                j++;
            }
            if(j==n)    
                return 1;
        }
        i++;
    }
    return 0;
}
