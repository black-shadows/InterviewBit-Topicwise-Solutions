int Solution::maxSum(vector<int> &A) 
{
    int sum[1024] = {0};
    int num;
    
    int n = A.size();
    
    for(int i = 0; i < n; i++)
    {
        num = A[i];
        int nm = 0;
        while(num)
        {
            nm |= (1 << (num % 10));
            num /= 10;
        }
        sum[nm] = max(sum[nm], A[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        num = A[i];
        int nm = 0;
        while(num)
        {
            nm |= (1 << (num % 10));
            num /= 10;
        }
        
        for(int j = 0; j < 1024; j++)
        {
            if((nm & j) == 0)
                sum[nm + j] = max(sum[nm + j], sum[nm] + sum[j]);
        }
    }
    
    int mx = 0;
    
    for(int i = 0; i < 1024; i++)
        mx = max(mx, sum[i]);
    return mx;
}
