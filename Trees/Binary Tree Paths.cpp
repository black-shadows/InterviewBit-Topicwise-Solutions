/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<vector<int> > ans;

void allBinaryTreepath(TreeNode *root,vector<int> &v){
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL){
        v.push_back(root->val);
        ans.push_back(v);
        v.pop_back();
        return;
    }
    v.push_back(root->val);
    allBinaryTreepath(root->left,v);
    allBinaryTreepath(root->right,v);
    v.pop_back();
}

vector<vector<int> > Solution::solve(TreeNode* A) {
    ans.clear();
    vector<int> v;
    allBinaryTreepath(A,v);
    return ans;
}