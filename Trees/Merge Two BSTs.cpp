/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


void inorder(TreeNode *root,vector<int> &a){
    if(root==NULL)
        return;
    inorder(root->left,a);
    a.push_back(root->val);
    inorder(root->right,a);
}

vector<int> mergetwobst(TreeNode *root1, TreeNode *root2)  {
    stack<TreeNode *> s1;
    TreeNode *current1 = root1;
    stack<TreeNode *> s2;
    vector<int> ans;
    TreeNode *current2 = root2;
    if (root1 == NULL) {
        inorder(root2,ans);
        return ans;
    }
    if (root2 == NULL)  {
        inorder(root1,ans);
        return ans;
    }

    while (current1 != NULL || !s1.empty() ||  current2 != NULL || !s2.empty())  {
        if (current1 != NULL || current2 != NULL )  {
            if (current1 != NULL)  {
                s1.push(current1);
                current1 = current1->left;
            }
            if (current2 != NULL)  {
                s2.push(current2);
                current2 = current2->left;
            }

        }
        else{
            if (s1.empty())  {
                while (!s2.empty())  {
                    current2 = s2.top();
                    s2.pop();
                    current2->left = NULL;
                    inorder(current2,ans);
                }
                return ans;
            }
            if (s2.empty())  {
                while (!s1.empty())  {
                    current1 = s1.top();
                    s1.pop();
                    current1->left = NULL;
                    inorder(current1,ans);
                }
                return ans;
            }
            current1 = s1.top();
            s1.pop();
            current2 = s2.top();
            s2.pop();
            if (current1->val < current2->val)  {
                ans.push_back(current1->val);
                current1 = current1->right;
                s2.push(current2);
                current2 = NULL;
            }
            else{
                ans.push_back(current2->val);
                current2 = current2->right;
                s1.push(current1);
                current1 = NULL;
            }
        }
    }
    return ans;
}

 
vector<int> Solution::solve(TreeNode* A, TreeNode* B) {
    return mergetwobst(A,B);
}