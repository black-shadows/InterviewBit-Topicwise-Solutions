#define MOD  1000000007
#define MAXN 101
#define left first
#define rite second

using namespace std;

using bint = unsigned long long int;
using pii = pair<int, int>;

bint table[MAXN]; // table[n] == (2^n)%1000000007

void init_table(){
    table[0] = 1;
    for(int i=1 ; i<MAXN ; ++i) table[i] = (table[i-1]<<1)%MOD;
}

int height(const int size){
    int h=0;
    while(table[h] <= size)     h++;
    return h;
}

bint povar(bint base, bint p){
    if(!p)  return 1;
    bint res = povar((base*base)%MOD, p/2);
    if(p%2)     res = (res*base)%MOD;
    return res;
}

bint C(int n, int k){
    // since C(n, k) == C(n, n-k)
    if(k > n/2)     k = n-k;
    
    bint res = 1;
    for(int i=0 ; i<k ; ++i, --n)    res = (res*n)%MOD;
    for(int i=1 ; i<=k ; ++i)        res = (res*povar(i, MOD-2))%MOD;
    
    return res;
}

pii subtrees(const int n){
    if(n < 2)   return make_pair(0, 0);
    int h = height(n);
    int last_row = n - (table[h-1]-1);
    int max_lrow = table[h-1];
    int l = table[h-2] - 1 + min(max_lrow/2, last_row);
    int r = n - l - 1;
    return make_pair(l, r);
}

bint zolve(const int n){
    if(n < 3)   return 1;
    pii childz = subtrees(n);
    int l = childz.left;
    int r = childz.rite;
    return (((C(n-1, l)*zolve(l))%MOD)*zolve(r))%MOD;
}


int Solution::solve(int A) {
    init_table();
    return zolve(A);
}
