/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int printCommon(TreeNode *root1, TreeNode *root2) 
{ 
    // Create two stacks for two inorder traversals 
    stack<TreeNode *> stack1, s1, s2; 
    
    int sum = 0;
  
    while (1) 
    { 
        // push the Nodes of first tree in stack s1 
        if (root1) 
        { 
            s1.push(root1); 
            root1 = root1->left; 
        } 
  
        // push the Nodes of second tree in stack s2 
        else if (root2) 
        { 
            s2.push(root2); 
            root2 = root2->left; 
        } 
  
        // Both root1 and root2 are NULL here 
        else if (!s1.empty() && !s2.empty()) 
        { 
            root1 = s1.top(); 
            root2 = s2.top(); 
  
            // If current keys in two trees are same 
            if (root1->val == root2->val) 
            { 
                sum = sum + root1->val;
                s1.pop(); 
                s2.pop(); 
  
                // move to the inorder successor 
                root1 = root1->right; 
                root2 = root2->right; 
            } 
  
            else if (root1->val < root2->val) 
            { 
                // If Node of first tree is smaller, than that of 
                // second tree, then its obvious that the inorder 
                // successors of current Node can have same value 
                // as that of the second tree Node. Thus, we pop 
                // from s2 
                s1.pop(); 
                root1 = root1->right; 
  
                // root2 is set to NULL, because we need 
                // new Nodes of tree 1 
                root2 = NULL; 
            } 
            else if (root1->val > root2->val) 
            { 
                s2.pop(); 
                root2 = root2->right; 
                root1 = NULL; 
            } 
        } 
  
        // Both roots and both stacks are empty 
        else  break; 
    } 
    
    return sum;
} 
 
int Solution::solve(TreeNode* A, TreeNode* B) 
{
    
    return printCommon(A, B);
    
}
