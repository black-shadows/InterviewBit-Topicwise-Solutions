/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int answer(TreeNode *A){
    if(!A)
        return INT_MIN;
    int sum=INT_MIN;
    int left=answer(A->left);
    int right=answer(A->right);
    if(A->left && A->right){
        sum=A->left->val+A->right->val+A->val;
        if(A->left->val >= A->right->val){
            if(A->val+A->left->val > A->val)
                A->val+=A->left->val;
            sum=max(sum,A->val);
        }else{
            if(A->val+A->right->val >A->val)
                A->val+=A->right->val;
            sum=max(sum,A->val);
        }
    }else if(A->left){
        if(A->val+ A->left->val >A->val)
            A->val+=A->left->val;
        sum=max(sum,A->val);
    }else if(A->right){
        if(A->val+A->right->val>=A->val)
            A->val+=A->right->val;
        sum=max(A->val,sum);
    }else return A->val;
    return max(sum,max(left,right));
}
int Solution::maxPathSum(TreeNode* A) {
    int ans=answer(A);
    return max(ans,A->val);
        
}