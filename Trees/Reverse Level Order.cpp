vector<int> Solution::solve(TreeNode* A) {
    vector<int> G,i;
    queue<TreeNode* > Q;
    TreeNode* root = A;
    Q.push(A);
    while(!Q.empty()){
        root = Q.front();
        Q.pop();
        G.push_back(root->val);
        if(root->right) Q.push(root->right);
        if(root->left) Q.push(root->left);
    }
    for(int j = G.size()-1;j>=0;j--){
        cout<<G[j]<<" ";
    }
    return i;
}