vector<int> Solution::solve(vector<int> &A) 
{
    
    int size = A.size();
    int posStartIndex = 0, i, j, temp;
    
    for (i = 0; i < size; i++) 
    {
        if (A[i] < 0) 
        {
            int temp = A[i];
            for (j = i; j > posStartIndex; j--) 
            {
                A[j] = A[j-1];
            }
            A[posStartIndex] = temp;
            posStartIndex++;
        }
    }
    
    int pos = posStartIndex, neg = 1;

    while (pos < size && neg < pos && A[neg] < 0)
    {
        i = pos; 
        temp = A[i];
        while(i > neg)
        {
            A[i] = A[i-1];
            i--;
        }
        A[neg] = temp;
        
        neg += 2;
        pos++;
    }
    return A;
}
