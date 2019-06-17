/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int differencebetweenoddandevenlevels(TreeNode *root){
    queue<TreeNode *> q;
    if(root==NULL)
        return 0;
    int oddsum=0;
    int evensum=0;
    int level=0;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        level^=1;
        while(n--){
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            if(level)
                oddsum+=temp->val;
            else
                evensum+=temp->val;
    }
}
    return (oddsum-evensum);
}
int Solution::solve(TreeNode* A) {
    return differencebetweenoddandevenlevels(A);
}