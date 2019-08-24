void trav(TreeNode *A)
 {
    if(A==NULL)
        return ;
    A->val=0;
    trav(A->left);
    trav(A->right);
 }
 int v(TreeNode* A)
 {
     if(A==NULL)
        return 0;
    if(A->right==NULL && A->left==NULL)
        return 0;
    if(A->val!=0)
        return A->val;
    int s1=1+v(A->left)+v(A->right);
    int s2=0;
    if(A->left!=NULL)
        s2+=1+v(A->left->left)+v(A->left->right);
    if(A->right!=NULL)
        s2+=1+v(A->right->left)+v(A->right->right);
    return A->val=min(s2,s1);    
 }
int Solution::solve(TreeNode* A) {
    int count=0;
    trav(A);
    return v(A);
}