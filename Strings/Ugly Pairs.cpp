int Solution::solve(string A) {
    
    string odd = "";
    string even = "";
    
    for(int i = 0; i < A.length(); i++)
    {
        if((int)A[i] % 2 == 1)
        {
            odd = odd + A[i];
        }
        else
        {
            even = even + A[i];
        }
    }
    
    for(int i = 0; i < even.length(); i++)
    {
        for(int j = 0; j < odd.length(); j++)
        {
            if((((int)even[i] + 1) != (int)odd[j]) && (((int)even[i] - 1) != (int)odd[j]))
            {
                return 1;
            }
                
        }
    }
    
    return 0;
}
