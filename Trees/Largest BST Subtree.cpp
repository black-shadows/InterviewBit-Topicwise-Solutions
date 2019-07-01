struct Info {
    int sz;
    int mx;
    int mn;
    int ans;
    bool isBST;
};

Info largestBSTinBinaryTree(TreeNode* root) {
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};

    if (root->left == NULL && root->right == NULL)
        return {1, root->val, root->val, 1, true};

    Info l = largestBSTinBinaryTree(root->left);
    Info r = largestBSTinBinaryTree(root->right);

    Info ret;
    ret.sz = (1 + l.sz + r.sz);

    if (l.isBST && r.isBST && l.mx < root->val && r.mn > root->val) {
        ret.mn = min(l.mn, min(r.mn, root->val));
        ret.mx = max(r.mx, max(l.mx, root->val));
        ret.ans = ret.sz;
        ret.isBST = true;
        return ret;
    }

    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;
    return ret;
}

 
int Solution::solve(TreeNode* A) {
    Info res=largestBSTinBinaryTree(A);
    return res.ans;
}

