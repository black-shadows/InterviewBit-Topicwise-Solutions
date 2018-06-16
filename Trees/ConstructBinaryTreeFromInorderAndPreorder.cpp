int findIndex(vector<int> &inorder, int i, int j, int val)
{
    for (auto b = i; b<=j; ++b)
        if (inorder[b]==val)
            return b;
}
TreeNode* makeTree(vector<int> &preorder, vector<int> &inorder, int i, int j, int& p)
{
    if (i>j)
        return NULL;
    TreeNode* node = new TreeNode(preorder[p++]);
    if (i==j)
        return node;
    int in = findIndex(inorder, i, j, node->val);
    node->left = makeTree(preorder, inorder, i, in-1, p);
    node->right = makeTree(preorder, inorder, in+1, j, p);
    return node;
}
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty())
        return NULL;
    int p = 0;
    return makeTree(preorder, inorder, 0, inorder.size()-1, p);
}