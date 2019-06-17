long CountOne3(long n)
{
    long count = 0;
    long i = 1;
    long current = 0, after = 0, before = 0;
    while((n / i) != 0)
    {
        current = (n / i) % 10;
        before = n / (i * 10);
        after = n - (n / i) * i;
        if (current > 1)
            count = count + (before + 1) * i;
        else if (current == 0)
            count = count + before * i;
        else if(current == 1)
            count = count + before * i + after + 1;
        i *= 10;
    }
    return count;
}

int Solution::solve(int A) 
{
    
    return CountOne3(A);
    
}
