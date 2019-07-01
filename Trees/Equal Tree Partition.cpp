long f(TreeNode* x) {
     return x?x->val+f(x->left)+f(x->right):0L;
}
long g(TreeNode* x, long s, bool& res) {
    if(!x)return 0;
    long a = g(x->left, s, res);
    long b = g(x->right, s, res);
    if(x->left&&a==s)res=true;
    if(x->right&&b==s)res=true;
    return a+x->val+b;
}
int Solution::solve(TreeNode* A) {
    long s = f(A);
    if(!A||(s&1))return 0;
    bool res=false;
    g(A,s/2,res);
    return res;
}
