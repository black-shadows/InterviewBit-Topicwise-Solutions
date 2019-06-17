long long power(long long base, long long exp, long long modulo)
{
    if (!exp) {
        return 1;
    }
    long long halfPower = power(base, exp / 2, modulo);
    long long fullPower = halfPower * halfPower;
    fullPower %= modulo;
    if (exp % 2 == 1) {
        fullPower *= base;
    }
    fullPower %= modulo;
    return fullPower;
}

long long inverse(long long n, long long modulo)
{
    return power(n, modulo - 2, modulo);
}

long long factorial(long long n, long long modulo)
{
    long long f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
        f %= modulo;
    }
    return f;
}

int Solution::solve(int n)
{
    long long modulo = 1000000007;
    long long nom = 1;
    for (long long i = n + 2; i <= 2 * n; i++) {
        nom *= i;
        nom %= modulo;
    }
    long long denom = 1;
    for (long long i = 1; i <= n; i++) {
        denom *= i;
        denom %= modulo;
    }
    long long r = (nom * inverse(denom, modulo)) % modulo;
    return r;
}