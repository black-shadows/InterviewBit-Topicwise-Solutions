/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
unordered_map<TreeNode*, TreeNode*> uMap;

void mapParentNode(TreeNode* root,TreeNode* parent) {
    if (!root)
        return;
    uMap[root]=parent;
    mapParentNode(root->left,root);
    mapParentNode(root->right,root);
}

vector<int> solveit(TreeNode *root,TreeNode* target,int k){
    uMap.clear();
    vector<int> res;
    queue<TreeNode*> q;
    unordered_set<TreeNode*> visited;
    TreeNode* curr;
    int width=0;
    int level=0;
    if(root==NULL)
        return res;
    if(k==0){
        res.push_back(target->val);
        return res;
    }
    mapParentNode(root,NULL);
    q.push(target);
    visited.insert(target);
    while (!q.empty()) {
                width = q.size();
                for (int i=0; i<width; ++i){
                    curr = q.front();
                    q.pop();
                    if (level == k) {
                        res.push_back(curr->val);
                    }
                    else {
                        if ( uMap[curr] && (visited.find(uMap[curr]) == visited.end()) ) {
                            q.push(uMap[curr]);
                            visited.insert(uMap[curr]);
                        }
                        if ( curr->left && (visited.find(curr->left) == visited.end()) ) {
                            q.push(curr->left);
                            visited.insert(curr->left);
                        }
                        if ( curr->right && (visited.find(curr->right) == visited.end()) ) {
                            q.push(curr->right);
                            visited.insert(curr->right);
                        }
                    }
                }
                level++;
            }

    return res;
}

vector<int> doit(TreeNode *root,int target,int k){
    TreeNode *targetpointer = NULL;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *temp=q.front();
        q.pop();
        if(temp->val==target){
            targetpointer=temp;
            break;
        }
    if(temp->left)
        q.push(temp->left);
    if(temp->right)
        q.push(temp->right);
    }
    assert(targetpointer!=NULL);
    return solveit(root,targetpointer,k);
}
 
vector<int> Solution::solve(TreeNode* A, int B, int C) {
    return doit(A,B,C);
}