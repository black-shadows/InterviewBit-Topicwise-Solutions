int ans=0;

void dfs(TreeNode *root,int v,int out) {
    if (!root)
        return ;
    if (root->val==v+1)
        ++out ;
    else
        out=1 ;
    ans=max(ans, out);
    dfs(root->left,root->val,out);
    dfs(root->right,root->val,out);
}
int longestConsecutive(TreeNode* root) {
    if (!root)
        return  0;
    ans=0;
    dfs(root,root->val, 0);
    return ans;
}

int Solution::solve(TreeNode* A) {
    return longestConsecutive(A);
}
