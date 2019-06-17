/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* This function is used  
to increment left subtree */
void increment(TreeNode *node, int diff);  
  
/* This function changes a tree  
to to hold children sum property */
void convertTree(TreeNode *node)  
{  
    int left_data = 0, right_data = 0, diff;  
      
    /* If tree is empty or it's a leaf   
        node then return true */
    if (node == NULL || (node->left == NULL && node->right == NULL))  
        return;  
    else
    {  
        /* convert left and right subtrees */
        convertTree(node->left);  
        convertTree(node->right);  
      
        /* If left child is not present then 0 is used  
        as data of left child */
        if (node->left != NULL)  
        left_data = node->left->val;  
      
        /* If right child is not present then 0 is used  
        as data of right child */
        if (node->right != NULL)  
        right_data = node->right->val;  
      
        /* get the diff of node's data and children sum */
        diff = left_data + right_data - node->val;  
      
        /* If node's children sum is  
        greater than the node's data */
        if (diff > 0)  
        node->val = node->val + diff;  
      
        /* THIS IS TRICKY --> If node's data 
        is greater than children sum,  
        then increment subtree by diff */
        if (diff < 0)  
        increment(node, -diff); // -diff is used to make diff positive  
    }  
}  
  
/* This function is used  
to increment subtree by diff */
void increment(TreeNode *node, int diff)  
{  
    /* IF left child is not  
    NULL then increment it */
    if(node->left != NULL)  
    {  
        node->left->val = node->left->val + diff;  
      
        // Recursively call to fix  
        // the descendants of node->left  
        increment(node->left, diff);  
    }  
    else if (node->right != NULL) // Else increment right child  
    {  
        node->right->val = node->right->val + diff;  
      
        // Recursively call to fix  
        // the descendants of node->right  
        increment(node->right, diff);  
    }  
}  
  
 
TreeNode* Solution::solve(TreeNode* A) 
{
    
    convertTree(A);
    
    return A;
    
}
