/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

unordered_set<string> subtrees;
string MARKER ="$";

string check(TreeNode *root) {
    string s = "";
    if (root == NULL)
        return s + MARKER;
    string lStr = check(root->left);
    if (lStr.compare(s) == 0)
       return s;
    string rStr = check(root->right);
    if (rStr.compare(s) == 0)
       return s;
    string p;
    assert(root->val>=0&&root->val<10);
    p.push_back(root->val+'0');
    s = s + p + lStr + rStr;
    if (s.length() > 3 &&subtrees.find(s) != subtrees.end())
       return "";
    subtrees.insert(s);
    return s;
}

int checkduplicatesubtree(TreeNode *root){
    subtrees.clear();
    string ch1=check(root);
    if(ch1.compare("")==0)
        return 1;
    return 0;
}
int Solution::solve(TreeNode* A) {
    return checkduplicatesubtree(A);
}