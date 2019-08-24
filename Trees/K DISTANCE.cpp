int BIT[200000];
#define ni 200000
void update(int x, int delta)       
{
    for(; x <= ni; x += x&-x)
          BIT[x] += delta;
}
int query(int x)      
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}
#define mod 1000000007
int Solution::solve(TreeNode* A, int B) {
    if(A == NULL)
    {
        return 0;
    }

    update(A->val,1);
    int val1 = solve(A->left,B);
    int val2 = solve(A->right,B);
    update(A->val, -1);
    return  (val1+val2+query(min(A->val+B,100000)) - query(max(A->val-B-1,0)))%mod;
}
