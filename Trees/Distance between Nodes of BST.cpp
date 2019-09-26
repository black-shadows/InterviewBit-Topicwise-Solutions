int distanceFromRoot(TreeNode* root, int x)
{
    if (root->val == x)
        return 0;
    else if (root->val > x)
        return 1 + distanceFromRoot(root->left, x);
    return 1 + distanceFromRoot(root->right, x);
}


int distanceBetween2(TreeNode* root, int a, int b)
{
    if (!root)
        return 0;

    if (root->val > a && root->val > b)
        return distanceBetween2(root->left, a, b);


    if (root->val < a && root->val < b)
        return distanceBetween2(root->right, a, b);


    if (root->val >= a && root->val <= b)
        return distanceFromRoot(root, a) +
               distanceFromRoot(root, b);
}
int Solution::solve(TreeNode *A, int B, int C)
{
   if (B > C)
     swap(B, C);
   return distanceBetween2(A, B, C);
}