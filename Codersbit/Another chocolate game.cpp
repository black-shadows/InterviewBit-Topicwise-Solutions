#define mod 1000000007

vector<int> factorial(100001);
int flag = 0;
void Factorial(void)
{
    flag = 1;
    factorial[0] = 1;
    factorial[1] = 1;
    long long Fact = 1LL;
    for(int i = 2; i <= 100000; i++){
        Fact = (Fact*i)%mod;
        factorial[i] = Fact;
    }
}

long long Inverse(int n, int deg)
{
    long long res = 1LL, curr = n;
    while(deg){
        if(deg%2 != 0)
            res = (res*curr)%mod;
        deg/=2;
        curr = (curr*curr)%mod;
    }
    return res%mod;
}

int Solution::solve(int A, int B) {
    if(B < A)
        return 0;
        
    if(flag == 0)
        Factorial();
        
    if(A == B)
        return factorial[B];
        
    return (factorial[B]*Inverse(factorial[B-A],mod-2))%mod;
}
