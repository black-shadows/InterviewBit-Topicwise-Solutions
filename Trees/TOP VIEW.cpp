vector<int> topview(TreeNode* root) 
{ 
    vector <int> ans;
    if(root==NULL) 
       return ans; 
     queue<TreeNode*>q; 
     map<int,int> m;
     map<int,int> l;
     int hd=0; 
     l[root->val] = hd; 
       
     q.push(root); 
      
     while(q.size()) 
     { 
        hd=l[root->val]; 
          
        if(m.count(hd)==0)   
        m[hd]=root->val; 
        if(root->left) 
        { 
            l[root->left->val] = hd-1LL; 
            q.push(root->left); 
        } 
        if(root->right) 
        { 
            l[root->right->val]=hd+1; 
            q.push(root->right); 
        } 
        q.pop(); 
        root=q.front(); 
        
    } 
      
      
     for(auto i=m.begin();i!=m.end();i++) 
    { 
        ans.push_back(i->second); 
    } 
      return ans;
} 

vector<int> Solution::solve(TreeNode* A) {
    return topview(A);
}