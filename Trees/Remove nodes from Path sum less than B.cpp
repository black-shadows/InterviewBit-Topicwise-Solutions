/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
TreeNode *pruneUtil(TreeNode *root, int k, int *sum) 
{ 
    // Base Case 
    if (root == NULL)  return NULL; 
  
    // Initialize left and right sums as sum from root to 
    // this node (including this node) 
    int lsum = *sum + (root->val); 
    int rsum = lsum; 
  
    // Recursively prune left and right subtrees 
    root->left = pruneUtil(root->left, k, &lsum); 
    root->right = pruneUtil(root->right, k, &rsum); 
  
    // Get the maximum of left and right sums 
    *sum = max(lsum, rsum); 
  
    // If maximum is smaller than k, then this node 
    // must be deleted 
    if (*sum < k) 
    { 
        free(root); 
        root = NULL; 
    } 
  
    return root; 
} 
  
// A wrapper over pruneUtil() 
TreeNode *prune(TreeNode *root, int k) 
{ 
    int sum = 0; 
    return pruneUtil(root, k, &sum); 
} 
 
 
TreeNode* Solution::solve(TreeNode* A, int B) 
{
    
    return prune(A, B);
    
}
