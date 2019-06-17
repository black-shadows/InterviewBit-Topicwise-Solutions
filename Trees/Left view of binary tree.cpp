/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> leftview(TreeNode *root){
    vector<int> ans;
    queue<TreeNode *> q;
    if(root==NULL)
        return ans;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode *temp=q.front();
        if(temp){
            ans.push_back(temp->val);
            while(q.front()!=NULL){
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                q.pop();
                temp=q.front();
            }
            q.push(NULL);
        }
    q.pop();
    }
return ans;
}
 
vector<int> Solution::solve(TreeNode* A) {
    return leftview(A);
}