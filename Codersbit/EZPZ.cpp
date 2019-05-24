bool isprime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}
int Solution::solve(int n) {
     if(n<2)
        return -1;
    if(isprime(n))
        return 1;
    if(n%2==0)
    {
        return 2;
    }
    if(isprime(n-2))
        return 2;
    return 3;
}
