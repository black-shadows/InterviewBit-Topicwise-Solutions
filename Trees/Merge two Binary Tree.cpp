TreeNode* Solution::solve(TreeNode* A, TreeNode* B)
{
    if (!A) return B;
    else if (!B) return A;
    
    A->val += B->val;
    A->left = solve(A->left,B->left);
    A->right = solve(A->right,B->right);
    return A;
}