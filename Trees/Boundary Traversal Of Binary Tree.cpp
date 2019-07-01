void inorder(TreeNode *root , vector<int> &ans){
     
     if(root==NULL)return ;
     
     inorder(root->left,ans);
     if(root->left==NULL&&root->right==NULL){
     ans.push_back(root->val);
     }
     inorder(root->right,ans);
 }
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    TreeNode *root=A;
    while(root->left!=NULL&&root->right!=NULL){
        while(root->left!=NULL)
        {
            ans.push_back(root->val);
            root = root->left;
        }
        if(root->right!=NULL)
        {
            root = root->right;
            ans.push_back(root->val);
        }
    }
    vector<int>right_bount;
    root = A;
     while(root->left!=NULL&&root->right!=NULL){
        while(root->right!=NULL)
        {
                root = root->right;
                right_bount.push_back(root->val);
        }
        if(root->left!=NULL)
        {
            root = root->left;
            right_bount.push_back(root->val);
        }
    }
    root = A;
    inorder(root,ans);
    reverse(right_bount.begin(),right_bount.end());
    
    ans.insert(ans.end(),right_bount.begin()+1,right_bount.end());
    return ans;
}
