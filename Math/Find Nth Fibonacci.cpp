#define ll long long
#define M 1000000007
struct mat
{
    ll a,b,c,d;
};
mat po(ll n)
{
    if(n==1)
    {
        mat in;
        in.a=1;
        in.b=1;
        in.c=1;
        in.d=0;
        return in;
    }
    if(n==2)
    {
        mat in;
        in.a=2;
        in.b=1;
        in.c=1;
        in.d=1;
        return in;
    }
    else
    {
        mat a=po(n/2);
        mat b;
        b.a=(a.a)*(a.a)+(a.b)*(a.c);
        b.b=(a.a)*(a.b)+(a.b)*(a.d);
        b.c=(a.a)*(a.c)+(a.c)*(a.d);
        b.d=(a.b)*(a.c)+(a.d)*(a.d);
        b.a%=M;
        b.b%=M;
        b.c%=M;
        b.d%=M;
        if(n%2==1)
        {
            mat c;
            c.a=b.a+b.b;
            c.b=b.a;
            c.c=b.c+b.d;
            c.d=b.c;
            c.a%=M;
            c.b%=M;
            c.c%=M;
            c.d%=M;
            return c;
        }
        return b;
    }
}
int Solution::solve(int A) {
    mat re=po(A);
    return re.c;
}