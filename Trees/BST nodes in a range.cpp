/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int countbstnodesingivenrange(TreeNode *root, int low, int high) {
    if (root==NULL)
        return 0;
    if (root->val == high && root->val == low)
        return 1;
    if (root->val <= high && root->val >= low)
         return 1 + countbstnodesingivenrange(root->left, low, high) + countbstnodesingivenrange(root->right, low, high);
    else if (root->val < low)
         return countbstnodesingivenrange(root->right, low, high);
    else
        return countbstnodesingivenrange(root->left, low, high);
    return 0;
}
int Solution::solve(TreeNode* A, int B, int C) {
    return countbstnodesingivenrange(A,B,C);
}