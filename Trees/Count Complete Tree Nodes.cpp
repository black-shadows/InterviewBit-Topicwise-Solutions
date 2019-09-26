int getDepth(TreeNode *root) {
    int depth = 0;
    while(root) {
        root = root->left;
        depth++;
    }
    return depth-1;
}

bool checkNode(TreeNode *root, int count) {
    // check if (count)th node exists
    vector<bool> path;
    while(count > 1) {
        path.push_back(count & 1);
        count >>= 1;
    }
    for(int i=path.size()-1; i>=0; i--)
        if(path[i]) root = root->right;
        else root = root->left;
    return root;
}
int Solution::solve(TreeNode* A) {
    if(!A) return 0;
    
    int depth = getDepth(A);
    // binary search on number of nodes
    int lo = 1 << depth, hi = lo*2 - 1, mid;
    while(lo < hi) {
        mid = lo + (hi - lo + 1)/2;
        if(checkNode(A, mid)) lo = mid;
        else hi = mid-1;
    }
    
    if(checkNode(A, lo)) return lo;
    return lo - 1;
}
