/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int maxDepth = -1;
TreeNode* first ;
TreeNode* second;

void DFS(TreeNode* root, int depth) {
    if (root==NULL)
        return;
    if (root->left==NULL && root->right==NULL) {
        if (depth > maxDepth) {
            first = root;
            second = NULL;
            maxDepth = depth;
        }
        else if (depth == maxDepth) {
            second = root;
        }
    }
    DFS(root->left, depth + 1);
    DFS(root->right, depth + 1);
}

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root)
        return NULL;
    if (p == root || q == root)
        return root;
    auto left = lca(root->left, p, q);
    auto right = lca(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

 
TreeNode* Solution::solve(TreeNode* A) {
    if (!A)
        return A;

    maxDepth = -1;
    first = NULL;
    second = NULL;
    DFS(A, 0);
    return !second ? first : lca(A, first, second);
    
}