int Solution::solve(TreeNode* A) {
     if(A==NULL) return 0;
    int ans = A->val, sz,sum;
    queue<TreeNode*> q;
    q.push(A);
    TreeNode*  p;
    
    while(!q.empty()){
        sz=q.size();
        sum=0;
        while(sz--){
            p=q.front();
            sum+=(p->val);
            q.pop();
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        ans = max(sum,ans);
    }
    
    return ans;
}
