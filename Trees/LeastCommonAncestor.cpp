bool find(TreeNode* root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    if ((root->left && find(root->left, val)) || 
        (root->right && find(root->right, val)))
        return true;
    return false;
}

TreeNode* LCA(TreeNode* root, int val1, int val2)
{
    if (!root || root->val == val1 || root->val == val2)
        return root;
    
    auto L = LCA(root->left, val1, val2);
    auto R = LCA(root->right, val1, val2);
    
    if (L && R)
        return root;
    return L ? L : R;
}

int Solution::lca(TreeNode* A, int val1, int val2) {
    if (!find(A, val1) || !find(A, val2))
        return -1;
    auto ancestor = LCA(A, val1, val2);
    if (ancestor)
        return ancestor->val;
    return -1;
}