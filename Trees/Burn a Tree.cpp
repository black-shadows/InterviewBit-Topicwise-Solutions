bool sol(TreeNode*root,int &h,int &ans,int B)
{
    if(root==NULL)
    return false;
    int hl=0,hr=0;
    bool lf=sol(root->left,hl,ans,B);
    bool rf=sol(root->right,hr,ans,B);
    if(!lf&&!rf)
    h=1+max(hl,hr);
    else
    if(lf)
    h=hl+1;
    else
    h=hr+1;
    if(B==root->val||lf||rf)
    {
        ans=max(ans,hl+hr+1);
        return true;
    }
    else
    return false;
}
int Solution::solve(TreeNode* A, int B) {
    int ans=0,h=0;
    sol(A,h,ans,B);
    return ans-1;
}
