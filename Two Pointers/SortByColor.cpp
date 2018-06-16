void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int c0=0,c1=0,c2=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == 0)
        {
            c0++;
        }
        else if(A[i] == 1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
        
    }
    for(int i=0;i<c0;i++)
    {
        A[i] = 0;
    }

    for(int i=0;i<c1;i++)
    {
        A[c0+i] = 1;
    }
    for(int i=0;i<c2;i++)
    {
        A[c0+c1+i] = 2;
    }
}