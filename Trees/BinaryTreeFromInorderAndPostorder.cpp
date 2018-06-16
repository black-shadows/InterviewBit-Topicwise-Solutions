int findIndex(vector<int>& inorder, int i, int j, int val)
{
    for (auto b = i; b<=j; ++b)
        if (inorder[b] == val)
            return b;
}

TreeNode* makeTree(vector<int> &inorder, vector<int> &postorder, int i, int j, int& p)
{
    if (i>j)
        return NULL;
    TreeNode* node = new TreeNode(postorder[p--]);
    if (i==j)
        return node;
    int in = findIndex(inorder, i, j, node->val);
    node->right = makeTree(inorder, postorder, in+1, j, p);
    node->left = makeTree(inorder, postorder, i, in-1, p);
    return node;
}
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int p = postorder.size()-1;
    return inorder.empty() ? NULL : makeTree(inorder, postorder, 0, inorder.size()-1, p);
}