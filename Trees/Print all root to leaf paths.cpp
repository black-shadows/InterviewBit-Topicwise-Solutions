/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void printPathsRecur(TreeNode *node, int path[], int pathLen, vector<vector<int>> &ans)  
{  
    if (node == NULL)  
        return;  
      
    /* append this node to the path array */
    path[pathLen] = node->val;  
    pathLen++;  
    
    /* it's a leaf, so print the path that led to here */
    if (node->left == NULL && node->right == NULL)  
    {  
        vector<int> result;
        
        for(int i=0; i<pathLen; i++)
        {
            
            result.push_back(path[i]);
            
        }
        
        ans.push_back(result);
    }  
    else
    {  
        /* otherwise try both subtrees */
        printPathsRecur(node->left, path, pathLen, ans);  
        printPathsRecur(node->right, path, pathLen, ans);  
    }  
} 
 
vector<vector<int>> printPaths(TreeNode *node)  
{
    vector<vector<int>> ans;
    int path[1000];  
    printPathsRecur(node, path, 0, ans);  
    return ans;
}  
 
vector<vector<int> > Solution::solve(TreeNode* A) 
{
    
    return printPaths(A);
    
}
