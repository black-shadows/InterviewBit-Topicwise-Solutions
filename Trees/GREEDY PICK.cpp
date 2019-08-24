#define ll long long
#define mod 1000000007 
vector<int> robSub(TreeNode* root) {
    if (root == NULL) {
        return vector<int>(2,0LL);
    }

    vector<int> left = robSub(root->left);
    vector<int> right = robSub(root->right);

    vector<ll> res(2,0LL);
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = root->val + left[0] + right[0];
    res[0]%=mod;
    res[1]%=mod;
    vector<int> ans(2);
    ans[0] = res[0];
    ans[1] = res[1];
    return ans;
}
int Solution::solve(TreeNode* A) {
    vector<int> res = robSub(A);
    return max(res[0], res[1]);
}
